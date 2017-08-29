#include "main.h"


int func_only_pid_write_file(FILE * fp, char * output_file,long pid_input_long){
  unsigned char buf[188];
  FILE * fp_write;

  if((fp_write=fopen(output_file,"wb"))==NULL){
    puts("write file error");
    return -1;
  }

  unsigned char pid_input[2];
  pid_input[0] = pid_input_long>>8;
  pid_input[1] = pid_input_long;
  unsigned char pid[2];

  size_t n_size;
  while (0<(n_size = fread(buf,1,188,fp))) {

    pid[0] = (buf[1]<<3)>>3;    //pid is 13bit
    pid[1] = buf[2];
#if DEBUG
      printf("----------------------------------------------\n");
      printf("PID       = 0x%02X%02X\nINPUT_PID = 0x%02X%02X\n",pid[0],pid[1],pid_input[0],pid_input[1]);
#endif

    if ((pid[0]==pid_input[0]) && (pid[1]==pid_input[1])) {
#if DEBUG
      printf("n_size = %d / buf[0] = %02X / buf[1] = %02X / buf[2] = %02X / buf[3] = %02X \n",n_size,buf[0],buf[1],buf[2],buf[3]);
#endif
      fwrite(buf,1,n_size,fp_write);
    }

  }

  fclose(fp_write);
  return 0;

}


int func_remove_pid_write_file(FILE * fp, char * output_file,long pid_input_long){
  unsigned char buf[188];
  FILE * fp_write;

  if((fp_write=fopen(output_file,"wb"))==NULL){
    puts("write file error");
    return -1;
  }

  unsigned char pid_input[2];
  pid_input[0] = pid_input_long>>8;
  pid_input[1] = pid_input_long;
  unsigned char pid[2];

  size_t n_size;
  while (0<(n_size = fread(buf,1,188,fp))) {

    pid[0] = (buf[1]<<3)>>3;    //pid is 13bit
    pid[1] = buf[2];
#if DEBUG
      printf("----------------------------------------------\n");
      printf("PID       = 0x%02X%02X\nINPUT_PID = 0x%02X%02X\n",pid[0],pid[1],pid_input[0],pid_input[1]);
#endif

    if (!((pid[0]==pid_input[0]) && (pid[1]==pid_input[1]))) {
#if DEBUG
      printf("n_size = %d / buf[0] = %02X / buf[1] = %02X / buf[2] = %02X / buf[3] = %02X \n",n_size,buf[0],buf[1],buf[2],buf[3]);
#endif
      fwrite(buf,1,n_size,fp_write);
    }

  }

  fclose(fp_write);
  return 0;

}
