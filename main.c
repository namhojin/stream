

#include "main.h"

#define INPUT_FILENAME argv[1]
#define WRITE_FILENAME argv[2]
#define WRITE_PATH "OUTPUT/"
#define INPUT_OPTION argv[3]
#define INPUT_OPTION_O "-o"
#define INPUT_OPTION_D "-d"
#define INPUT_PID argv[4]


int main(int argc, char* argv[]){

  FILE * fp;


  if (argc < 5) {
    printf("parameter error\nstream_mgr [input file] [output file] -o [pid(decimal)]\nstream_mgr [input file] [output file] -d [pid(decimal)]\n");
    printf("-o : only pid\n");
    printf("-d : delete pid\n");
    exit(1);
  }

#if DEBUG
  printf("%d option\n", argc-1);

  int i;
  for (i = 0; i < argc; i++) {
    printf("argv[%d] = %s\n", i,argv[i]);
  }
#endif

  if((fp=fopen(INPUT_FILENAME,"rb"))==NULL){
    puts("input file error");
    exit(1);
  }

  mkdir(WRITE_PATH,0777);

  char output_file[128];      //path + write file name
  strcpy(output_file,WRITE_PATH);
  strcat(output_file,WRITE_FILENAME);

  long pid_input_long;
  char *stop;
  pid_input_long=strtol(INPUT_PID,&stop,10);

  int result;
  if (!strcmp(INPUT_OPTION,INPUT_OPTION_O)) {
    result = func_only_pid_write_file(fp, output_file, pid_input_long);
  } else if (!strcmp(INPUT_OPTION,INPUT_OPTION_D)) {
    result = func_remove_pid_write_file(fp, output_file, pid_input_long);
  }



  if(result==-1){
    printf("func_write_file error\n");
  }



  fclose(fp);

  return 0;
}
