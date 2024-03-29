# include <stdio.h>
# include "am.h"
# include "pf.h"

// AM_PrintIntNode(pageBuf,attrType)
// char *pageBuf;
// char attrType;
// {
// int tempPageint;
// int i;
// int recSize;
// AM_INTHEADER *header;


// header = (AM_INTHEADER *) calloc(1,AM_sint);
// bcopy(pageBuf,header,AM_sint);
// recSize = header->attrLength + AM_si;
// printf("PAGETYPE %c\n",header->pageType);
// printf("NUMKEYS %d\n",header->numKeys);
// printf("MAXKEYS %d\n",header->maxKeys);
// printf("ATTRLENGTH %d\n",header->attrLength);
// bcopy(pageBuf + AM_sint,&tempPageint,AM_si);
// printf("FIRSTPAGE is %d\n",tempPageint);
// for(i = 1 ; i <= (header->numKeys);i++)
//   {
//    AM_PrintAttr(pageBuf + (i-1)*recSize + AM_sint + AM_si,attrType,
//                  header->attrLength);
//    bcopy(pageBuf + i*recSize + AM_sint,&tempPageint,AM_si);
//    printf("NEXTPAGE is %d\n",tempPageint);
//   }
// }


// AM_PrintLeafNode(pageBuf,attrType)
// char *pageBuf;
// char attrType;

// {
// short nextRec;
// int i;
// int recSize;
// int recId;
// int offset1;
// AM_LEAFHEADER *header;

// header = (AM_LEAFHEADER *) calloc(1,AM_sl);
// bcopy(pageBuf,header,AM_sl);
// recSize = header->attrLength + AM_ss;
// printf("PAGETYPE %c\n",header->pageType);
// printf("NEXTLEAFPAGE %d\n",header->nextLeafPage);
// /*printf("RECIDPTR %d\n",header->recIdPtr);
// printf("KEYPTR %d\n",header->keyPtr);
// printf("FREELISTPTR %d\n",header->freeListPtr);
// printf("NUMINFREELIST %d\n",header->numinfreeList);
// printf("ATTRLENGTH %d\n",header->attrLength);
// printf("MAXKEYS %d\n",header->maxKeys);*/
// printf("NUMKEYS %d\n",header->numKeys);
// for (i = 1; i <= header->numKeys; i++)
//   {
//   offset1 = (i - 1) * recSize + AM_sl;
//   AM_PrintAttr(pageBuf + AM_sl + (i-1)*recSize,attrType,header->attrLength);
//   bcopy(pageBuf + offset1 + header->attrLength,(char *)&nextRec,AM_ss);
//   while (nextRec != 0)
//     {
//     bcopy(pageBuf + nextRec,(char *)&recId,AM_si);
//     printf("RECID is %d\n",recId);
//     bcopy(pageBuf + nextRec + AM_si,(char *)&nextRec,AM_ss);
//     }
//   printf("\n");
//   printf("\n");
//   }
// }

// AM_DumpLeafPages(fileDesc,min,attrType,attrLength)
// int fileDesc;
// int min;
// int attrLength;
// char attrType;


// {
// int pageNum;
// char *value;
// char *pageBuf;
// int index;
// int errVal;
// AM_LEAFHEADER *header;
// int *t1;
// t1 = (int *) malloc(sizeof (int));
// (*t1)=0;

// value = malloc(AM_si);
// bcopy(&min,value,AM_si);
// printf("%d PAGE \n",AM_LeftPageNum);
// PF_GetThisPage(fileDesc,AM_LeftPageNum,&pageBuf,t1);
// header = (AM_LEAFHEADER *) calloc(1,AM_sl);
// bcopy(pageBuf,header,AM_sl);
// while(header->nextLeafPage != -1)
//   {
//    printf("PAGENUMBER = %d\n",pageNum);   
//    AM_PrintLeafKeys(pageBuf,attrType);
//    errVal = PF_UnfixPage(fileDesc,pageNum,FALSE);
//    AM_Check;
//    pageNum = header->nextLeafPage;   
//    errVal = PF_GetThisPage(fileDesc,pageNum,&pageBuf,t1);
//    AM_Check;
//    bcopy(pageBuf,header,AM_sl);
//   }
// printf("PAGENUMBER = %d\n",pageNum);
// AM_PrintLeafKeys(pageBuf,attrType);
// errVal = PF_UnfixPage(fileDesc,pageNum,FALSE);
// AM_Check;
// }



// AM_PrintLeafKeys(pageBuf,attrType)
// char *pageBuf;
// char attrType;

// {
// short nextRec;
// int i;
// int recSize;
// int recId;
// int offset1;
// AM_LEAFHEADER *header;

// header = (AM_LEAFHEADER *) calloc(1,AM_sl);
// bcopy(pageBuf,header,AM_sl);
// recSize = header->attrLength + AM_ss;
// for (i = 1; i <= header->numKeys; i++)
//   {
//   offset1 = (i - 1) * recSize + AM_sl;
//   AM_PrintAttr(pageBuf + AM_sl + (i-1)*recSize,attrType,header->attrLength);
//   bcopy(pageBuf + offset1 + header->attrLength,(char *)&nextRec,AM_ss);
//   while (nextRec != 0)
//     {
//     bcopy(pageBuf + nextRec,(char *)&recId,AM_si);
//     printf("RECID is %d\n",recId);
//     bcopy(pageBuf + nextRec + AM_si,(char *)&nextRec,AM_ss);
//     }
//   }
// }


// AM_PrintAttr(bufPtr,attrType,attrLength)
// char *bufPtr;
// char attrType;
// int attrLength;

// {
// int bufint;
// float buffloat;
// char *bufstr;

// switch(attrType)
//   {
//    case 'i' : {
//                bcopy(bufPtr,(char *)&bufint,AM_si);
//                printf("ATTRIBUTE is %d\n",bufint);
//                break;
//               }
//    case 'f' : {
//                bcopy(bufPtr,(char *)&buffloat,AM_sf);
//                printf("ATTRIBUTE is %d\n",buffloat);
//                break;
//               }
//    case 'c' : {
// 	       bufstr = malloc((unsigned) (attrLength + 1));
//                bcopy(bufPtr,bufstr,attrLength);
//                bufstr[attrLength] = '/0';
//                printf("ATTRIBUTE is %s\n",bufstr);
//                free(bufstr);
// 	       break;
//               }
//    }
// }


// AM_PrintTree(fileDesc,pageNum,attrType)
// int pageNum;
// int fileDesc;
// char attrType;

// {
// int nextPage;
// int errVal;
// AM_INTHEADER *header;
// char *tempPage;
// char *pageBuf;
// int recSize;
// int i;
// int *t1;
// t1 = (int *) malloc(sizeof (int));
// (*t1)=0;
// printf("GETTING PAGE = %d\n",pageNum);
// errVal = PF_GetThisPage(fileDesc,pageNum,&pageBuf,t1);
// tempPage = malloc(PF_PAGE_SIZE);
// bcopy(pageBuf,tempPage,PF_PAGE_SIZE);
// errVal = PF_UnfixPage(fileDesc,pageNum,FALSE);
// if (*tempPage == 'l')
//   {
//    printf("PAGENUM = %d\n",pageNum);
//    AM_PrintLeafKeys(tempPage,attrType);
//    return 1;
//   }
// header = (AM_INTHEADER *)calloc(1,AM_sint);
// bcopy(tempPage,header,AM_sint);
// recSize = header->attrLength + AM_si;
// for(i = 1; i <= (header->numKeys + 1); i++)
//   {
//    bcopy(tempPage + AM_sint + (i-1)*recSize,&nextPage,AM_si);
//    AM_PrintTree(fileDesc,nextPage,attrType);
//   }
// printf("PAGENUM = %d",pageNum);
// AM_PrintIntNode(tempPage,attrType);
// }


OurPrintTree(fileDesc,pageNum,attrType)
int pageNum;
int fileDesc;
char attrType;
{
  FILE *fp;
  fp = fopen("graph.gv", "w");
  fprintf(fp, "digraph BT{\n\tratio=auto\n\tsize=auto\n\tfixedsize = true;\n");
  AM_PrintTree(fileDesc, pageNum, attrType, fp);
  fprintf(fp, "}\n");
  fclose(fp);
  system("dot -Tpng graph.gv -o graph.png");
}


AM_PrintIntNode(pageBuf,attrType,fp)
char *pageBuf;
char attrType;
FILE* fp;
{
int tempPageint;
int i;
int recSize;
AM_INTHEADER *header;


header = (AM_INTHEADER *) calloc(1,AM_sint);
bcopy(pageBuf,header,AM_sint);
recSize = header->attrLength + AM_si;
// printf("PAGETYPE %c\n",header->pageType);
// printf("NUMKEYS %d\n",header->numKeys);
// printf("MAXKEYS %d\n",header->maxKeys);
// printf("ATTRLENGTH %d\n",header->attrLength);
bcopy(pageBuf + AM_sint,&tempPageint,AM_si);
fprintf(fp, "<ptr%d>|",tempPageint);
for(i = 1 ; i <= (header->numKeys);i++)
  {
   AM_PrintAttr(pageBuf + (i-1)*recSize + AM_sint + AM_si,attrType,
                 header->attrLength,fp);
   bcopy(pageBuf + i*recSize + AM_sint,&tempPageint,AM_si);
   if(i!=header->numKeys)
    fprintf(fp, "<ptr%d>|",tempPageint);
   else
    fprintf(fp, "<ptr%d>",tempPageint);
  }
}



AM_PrintLeafKeys(pageBuf,attrType,fp)
char *pageBuf;
char attrType;
FILE* fp;
{
short nextRec;
int i;
int recSize;
int recId;
int offset1;
AM_LEAFHEADER *header;

header = (AM_LEAFHEADER *) calloc(1,AM_sl);
bcopy(pageBuf,header,AM_sl);
recSize = header->attrLength + AM_ss + 2*AM_si;

AM_LEAFHEADER temp_head;
bcopy(pageBuf, &temp_head, AM_sl);
printf("Lol numKeys : %d  maxKeys: %d attrLength: %d\n", header->numKeys, header->maxKeys, header->attrLength);
  
for (i = 1; i <= header->numKeys; i++)
  {
  offset1 = (i - 1) * recSize + AM_sl;
  AM_PrintAttr(pageBuf + AM_sl + (i-1)*recSize,attrType,header->attrLength,fp);
  int key, ptr1, ptr2;
  short single;
  bcopy(pageBuf + AM_sl + (i-1)*recSize, &key, AM_si);
  bcopy(pageBuf + AM_sl + (i-1)*recSize+AM_si, &single, AM_ss);
  bcopy(pageBuf + AM_sl + (i-1)*recSize+AM_si+AM_ss, &ptr1, AM_si);
  bcopy(pageBuf + AM_sl + (i-1)*recSize+AM_si+AM_ss+AM_si, &ptr2, AM_si);
  printf("YAY  key: %d  single: %d  ptr1: %d  ptr2: %d\n", key, single, ptr1, ptr2);
  // bcopy(pageBuf + offset1 + header->attrLength,(char *)&nextRec,AM_ss);
  // while (nextRec != 0)
  //   {
  //   bcopy(pageBuf + nextRec,(char *)&recId,AM_si);
  //   bcopy(pageBuf + nextRec + AM_si,(char *)&nextRec,AM_ss);
  //   }
    if(i!=header->numKeys)
      fprintf(fp, "<ptr%d>|",recId);
    else
      fprintf(fp, "<ptr%d>",recId);
  }
  
}


AM_PrintAttr(bufPtr,attrType,attrLength,fp)
char *bufPtr;
char attrType;
int attrLength;
FILE* fp;
{
int bufint;
float buffloat;
char *bufstr;

switch(attrType)
  {
   //Changed only case i since this is what we need
   case 'i' : {
               bcopy(bufPtr,(char *)&bufint,AM_si);
               fprintf(fp, "<key%d>%d|",bufint,bufint);
               break;
              }
   case 'f' : {
               bcopy(bufPtr,(char *)&buffloat,AM_sf);
               printf("ATTRIBUTE is %d\n",buffloat);
               break;
              }
   case 'c' : {
         bufstr = malloc((unsigned) (attrLength + 1));
               bcopy(bufPtr,bufstr,attrLength);
               bufstr[attrLength] = '/0';
               printf("ATTRIBUTE is %s\n",bufstr);
               free(bufstr);
         break;
              }
   }
}


AM_PrintTree(fileDesc,pageNum,attrType,fp)
int pageNum;
int fileDesc;
char attrType;
FILE* fp;

{
int nextPage;
int errVal;
AM_INTHEADER *header;
char *tempPage;
char *pageBuf;
int recSize;
int i;
int *t1;
t1 = (int *) malloc(sizeof (int));
(*t1)=0;
int ptr;
// printf("GETTING PAGE = %d\n",pageNum);
errVal = PF_GetThisPage(fileDesc,pageNum,&pageBuf,t1);
tempPage = malloc(PF_PAGE_SIZE);
bcopy(pageBuf,tempPage,PF_PAGE_SIZE);
errVal = PF_UnfixPage(fileDesc,pageNum,FALSE);
if (*tempPage == 'l')
  {
   fprintf(fp, "page%d[shape=record, label=\"{{",pageNum);
   AM_PrintLeafKeys(tempPage,attrType,fp);
   fprintf(fp, "}}\"]\n");
   return 1;
  }
header = (AM_INTHEADER *)calloc(1,AM_sint);
bcopy(tempPage,header,AM_sint);
recSize = header->attrLength + AM_si;

fprintf(fp, "page%d[shape=record, label=\"{{",pageNum);
AM_PrintIntNode(tempPage,attrType,fp);
fprintf(fp, "}}\"]\n");

for(i = 1; i <= (header->numKeys + 1); i++)
  {
   bcopy(tempPage + AM_sint + (i-1)*recSize,&nextPage,AM_si);
   bcopy(tempPage + AM_sint + (i-1)*recSize, &ptr, AM_si);
   AM_PrintTree(fileDesc,nextPage,attrType, fp);
   fprintf(fp, "page%d:ptr%d->page%d\n", pageNum, ptr, nextPage);
  }

}

