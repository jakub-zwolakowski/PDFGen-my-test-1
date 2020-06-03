#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "pdfgen.h"

int main(int argc, char* argv[])
{
  struct pdf_info info;
  FILE *infile;
  infile = fopen (argv[1], "r");
  if (infile == NULL)
  {
    fprintf(stderr, "\nError opening file\n");
    exit (1);
  }
  if (fread(&info, sizeof(struct pdf_info), 1, infile) != 1)
  {
    fprintf(stderr, "\nFile too short (%zu)\n", sizeof(struct pdf_info));
    exit (1);
  }
  fclose(infile);

  struct pdf_doc *pdf = pdf_create(PDF_A4_WIDTH, PDF_A4_HEIGHT, &info);
  pdf_set_font(pdf, "Times-Roman");
  pdf_append_page(pdf);
  pdf_save(pdf, "fuzz.pdf");
  pdf_destroy(pdf);
  return 0;
}
