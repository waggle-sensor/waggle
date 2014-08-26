
.PHONY: all clean cleanall

TEX_FILES = bootSequencePaper.tex


all: $(TEX_FILES)
	latex bootSequencePaper
	bibtex bootSequencePaper
	latex bootSequencePaper
	latex bootSequencePaper
	dvipdf bootSequencePaper.dvi

clean:
	rm *~ *.aux *.log *.out *.ent *.bbl *.pdf *.blg *.dvi

cleanall: clean
	rm *.pdf
