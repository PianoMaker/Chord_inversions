#include"Notes.h"
#include"Messages.h"
void tableheader(string header, bool lang)
{
Message(11, header);
Line();
Message(11, table_header(lang));
Line();

}