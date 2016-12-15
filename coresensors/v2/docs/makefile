filename=v2dataExchange

pdf:	clean
	pdflatex ${filename}.tex
	pdflatex ${filename}.tex > /dev/null
	pdflatex ${filename}.tex > /dev/null

read: pdf
	evince ${filename}.pdf &

aread: pdf
	acroread ${filename}.pdf

all:  pdf

clean:
	rm -f ${filename}.log ${filename}.aux

