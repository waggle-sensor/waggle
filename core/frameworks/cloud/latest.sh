echo '<font face="courier new">' > data/latest.html
python server_scripts/ls.py | sed 's/ /\&nbsp;/g' | sed 's/\(data.*\)$/<a href=http:\/\/149.165.149.8\/\1>\1<\/a>/' | sed 's/$/<br>/' | grep '/5372696193135151419956/\|/85963139076892835624244/' >> data/latest.html
echo '<font face="courier new">' > data/latest_full.html
python server_scripts/ls.py | sed 's/ /\&nbsp;/g' | sed 's/\(data.*\)$/<a href=http:\/\/149.165.149.8\/\1>\1<\/a>/' | sed 's/$/<br>/' >> data/latest_full.html
echo '<font face="courier new">' > data/latest_uniq.html
python server_scripts/uniq.py | sed 's/ /\&nbsp;/g' | sed 's/\(data.*\)$/<a href=http:\/\/149.165.149.8\/\1>\1<\/a>/' | sed 's/$/<br>/' >> data/latest_uniq.html
python server_scripts/ls.py
