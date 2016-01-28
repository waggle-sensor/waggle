filename=sensorStreamFormat

pdf:
	pdflatex ${filename}.tex
	pdflatex ${filename}.tex

read: pdf
	evince ${filename}.pdf &

aread: pdf
	acroread ${filename}.pdf

all:  pdf

clean:
	rm -f ${filename}.log ${filename}.aux

