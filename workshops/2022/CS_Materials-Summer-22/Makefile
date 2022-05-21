all: agenda.html \
     slides/cloud9.pdf slides/bridgestutorial.pdf slides/coursestructure_csmat.pdf \
     slides/goingfurther.pdf slides/whatispossible.pdf slides/engagement_bridges.pdf \
     slides/objective.pdf

openswim.zip:
	./gen_openswim.sh

agenda.html: agenda.md
	cmark-gfm --extension table agenda.md > agenda.html

slides/cloud9.pdf: slides/cloud9.tex
	cd slides && pdflatex cloud9.tex

slides/bridgestutorial.pdf: slides/bridgestutorial.tex
	cd slides && pdflatex bridgestutorial.tex

slides/coursestructure_csmat.pdf: slides/coursestructure_csmat.tex
	cd slides && pdflatex coursestructure_csmat.tex

slides/goingfurther.pdf: slides/goingfurther.tex
	cd slides && pdflatex goingfurther.tex

slides/whatispossible.pdf: slides/whatispossible.tex
	cd slides && pdflatex whatispossible.tex

slides/engagement_bridges.pdf: slides/engagement_bridges.tex
	cd slides && pdflatex engagement_bridges.tex

slides/objective.pdf: slides/objective.tex
	cd slides && pdflatex objective.tex
