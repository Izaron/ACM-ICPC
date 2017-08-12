year=$1
g++ -std=c++11 markdown.cpp -o markdown
(cd $year && exec ../markdown<table >README.md)
rm markdown
