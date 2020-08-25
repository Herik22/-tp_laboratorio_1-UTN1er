#ifndef PARSER_H_INCLUDED
#define PARSER_H_INCLUDED

int parser_pilots_bytext(FILE* pFile,LinkedList* pLista);
int parser_flightbytext(FILE* pFile,LinkedList* pListFlight);

#endif // PARSER_H_INCLUDED
