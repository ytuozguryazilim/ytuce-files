#!/bin/bash
# https://unix.stackexchange.com/questions/155046/determine-if-git-working-directory-is-clean-from-a-script
if [ -z "$(git status --porcelain)" ]; then
  # Working directory clean
  echo "Clean!!!"
else
  # Uncommitted changes
  date_today=`date "+%d.%m.%y"`
  git add .
  git commit -m "$date_today"
  git push origin master
fi
