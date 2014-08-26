
.PHONY: all clean cleanall

TEX_FILES = introduction.tex \
			main.tex \
			power_efficiency.tex \
			privacy.tex \
			security.tex \
			survivability.tex

all: $(TEX_FILES)
	latex main
	bibtex main
	latex main
	latex main
	dvipdf main.dvi

clean:
	rm *~ *.aux *.log *.pdf *~ *.toc *.dvi *.out *.blg *.bbl

