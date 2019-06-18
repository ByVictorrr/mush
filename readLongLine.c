#include "readLongLine.h"


char *read_long_line(FILE *stream, int interactive)
{
	int index = 0;
	char *pbuff;
	int sizebuff = MAXCHAR;
	int c; /*temp is for moving allong pbuff*/

	/*initalize current size of buffer*/	
	int onebuff = 0;

	/*case 2: reading the whole file */
	pbuff = (char*)calloc(MAXCHAR, sizeof(char));
	memset(pbuff, '\0', MAXCHAR);
	
	if(interactive == INTERACTIVE){
		fwrite("8-P: ",1,strlen("8-P: "), stdout);
	}
	while((c = getc(stream)) != EOF){
		/*Case 1 - interactive cmd line mode read until "\n"*/
		if(interactive == INTERACTIVE){
			if(c == '\n')
				return pbuff;
		}
		pbuff[index++] = c;
		if ( index >= MAXCHAR-1 )
		{
			/*Size alloationa are alwaysgoing to be mutliples os MAXCHAr*/
			sizebuff = sizebuff + MAXCHAR;
			pbuff = (char*)realloc(pbuff,sizebuff);
		}
	}
	if(c == EOF && interactive == INTERACTIVE)
		exit(EXIT_FAILURE);

	return pbuff;
}

