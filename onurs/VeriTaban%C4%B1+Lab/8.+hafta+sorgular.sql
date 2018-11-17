/* ÖRNEK 1 */
CREATE OR REPLACE FUNCTION ornek1 (num1 NUMERIC, num2 NUMERIC) 
RETURNS numeric AS $$
DECLARE
toplam NUMERIC;
BEGIN
	toplam :=num1+num2;
	RAISE NOTICE 'sayi1:% , sayi2:%', num1, num2;
  	return toplam;
END;
$$ LANGUAGE  'plpgsql';

select ornek1(22,66);

/* ÖRNEK 2 */

CREATE TYPE yeni_tur
AS (isim VARCHAR(20), dep_isim VARCHAR(20), maas INTEGER);

CREATE FUNCTION ornek2 (eno employee.ssn%type) 
RETURNS yeni_tur AS $$
DECLARE 
	bilgi YENI_TUR; 
BEGIN 

SELECT 	fname, dname, salary INTO bilgi
FROM 	employee e, department d
WHERE 	e.dno = d.dnumber AND 
		e.ssn = eno;
		
	RAISE NOTICE 	'calisan ismi: %, departmanin ismi: %, maasi: % TLdir. ', 
			bilgi.isim, bilgi.dep_isim, bilgi.maas ; 	
	return bilgi; 
END; 
$$ LANGUAGE  'plpgsql';

select ornek2('123456789');

/* Örnek 3 */
CREATE FUNCTION ornek3 (dnum NUMERIC) 
RETURNS void AS $$
DECLARE 
	yeni_cur CURSOR FOR 	SELECT 	fname, lname 
				FROM 	employee 
				WHERE	dno = dnum;
BEGIN 

FOR satir IN yeni_cur LOOP
	RAISE INFO  'Employee name is % %', satir .fname, satir .lname;
END LOOP;
		
END; 
$$ LANGUAGE  'plpgsql';

select ornek3(8);

/* Örnek 4 */
CREATE FUNCTION ornek4 (dnum NUMERIC) 
RETURNS NUMERIC AS $$
DECLARE 
	toplam_maas NUMERIC;
	curs CURSOR FOR SELECT salary FROM employee WHERE dno = dnum;
BEGIN 

	toplam_maas := 0;
	FOR satir IN curs LOOP
		toplam_maas := toplam_maas  +  satir.salary;
	END LOOP;
	RETURN toplam_maas; 	
	
END; 
$$ LANGUAGE  'plpgsql';

select ornek4(8);

/* Örnek 5 */

CREATE  TRIGGER ornek5 
BEFORE INSERT
ON employee 
FOR EACH ROW EXECUTE PROCEDURE trig_fonk_ornek5();


CREATE FUNCTION trig_fonk_ornek5() 
RETURNS TRIGGER AS $$
BEGIN

	IF (	to_char(now(), 'DY') in ('SAT', 'SUN') OR 	
		to_char(now(), 'HH24') not between '08' and '18'	) THEN
		
		RAISE EXCEPTION 'Sadece mesai gunlerinde ve mesai saatlerinde insert yapabilirsiniz.';
		RETURN null;
	ELSE	
		RETURN new;
	END IF; 	
	
END; 
$$ LANGUAGE  'plpgsql';

INSERT INTO employee(fname, lname) VALUES('Ahmet', 'Mehmet');

/* Örnek 6 */
CREATE  TRIGGER ornek6 
AFTER UPDATE
ON department
FOR EACH ROW EXECUTE PROCEDURE trig_fonk_ornek6();


CREATE FUNCTION trig_fonk_ornek6() 
RETURNS TRIGGER AS $$
BEGIN

	UPDATE 	employee 
	SET	dno = new.dnumber 
	WHERE	dno = old.dnumber;

	RETURN new;
END; 
$$ LANGUAGE  'plpgsql';

UPDATE department SET dnumber=33 WHERE dnumber=8;

/* Örnek 7 */
CREATE  TRIGGER ornek7 
BEFORE UPDATE
ON employee
FOR EACH ROW EXECUTE PROCEDURE trig_fonk_ornek7();

CREATE FUNCTION trig_fonk_ornek7() 
RETURNS TRIGGER AS $$
BEGIN
	IF(	old.salary > new.salary OR new.salary>1.1*old.salary) THEN
		RAISE EXCEPTION 'Maasi dusuremezsiniz ve %%10dan fazla zam yapamazsınız.';
		RETURN old;
	ELSE
		RETURN new;
	END IF;	
END; 
$$ LANGUAGE  'plpgsql';

UPDATE employee SET salary = salary*1.2;