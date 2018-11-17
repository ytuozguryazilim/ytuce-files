
CREATE TABLE employee (
  fname    varchar(15) not null, 
  minit    varchar(1),
  lname    varchar(15) not null,
  ssn      char(9),
  bdate    date,
  address  varchar(50),
  sex      char,

  salary   int,
  superssn char(9),

  dno smallint,
  primary key (ssn),
  foreign key (superssn) references employee(ssn)

);


CREATE TABLE department (
  dname        varchar(25) not null,
 
  dnumber smallint,
  mgrssn       char(9) not null, 
  mgrstartdate date,
  primary key (dnumber),
  unique (dname),
  foreign key (mgrssn) references employee(ssn)
);



ALTER TABLE employee ADD CONSTRAINT foreign_key_const
  foreign key (dno) references department(dnumber);



CREATE TABLE dept_locations (

  dnumber smallint,
  dlocation varchar(15), 
  primary key (dnumber,dlocation),
  foreign key (dnumber) references department(dnumber)
);


CREATE TABLE project (
  pname      varchar(25) not null,
 
  pnumber smallint,
  plocation  varchar(15),

  dnum       smallint not null,
  primary key (pnumber),
  unique (pname),
  foreign key (dnum) references department(dnumber)
);


CREATE TABLE works_on (
  essn   char(9),

  pno    smallint,

 hours  smallint,
  primary key (essn,pno),
  foreign key (essn) references employee(ssn),
  foreign key (pno) references project(pnumber)
);


CREATE TABLE dependent (
  essn           char(9),
  dependent_name varchar(15),
  sex            char,
  bdate          date,
  relationship   varchar(8),
  primary key (essn,dependent_name),
  foreign key (essn) references employee(ssn)
);
