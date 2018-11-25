#include<stdio.h>
#include<stdlib.h>
#include "headers/firstSetup.h"
#include "headers/cJSON.h"

void displayOpenMessage();

void main(){
  int a = fileExist("data.json");
  setup();
  if(a==0){
    createFile("data.json");
  }else{
    displayOpenMessage();
  }
}

void displayOpenMessage(){
  FILE *file;
  long len = 0;
  char *data = NULL;
  cJSON *collage = NULL;
  file = fopen("data.json","rb");
  fseek(file,0,SEEK_END);
  len = ftell(file);
  fseek(file,0,SEEK_SET);
  data = (char*)malloc(len + 1);
  fread(data, 1, len,file);
  data[len] = '\0';
  fclose(file);
  cJSON *json = NULL;
  json = cJSON_Parse(data);
  if(!json){
    printf("%s\n","error" );
  }else{
    collage = cJSON_GetObjectItemCaseSensitive(json,"collage");
    cJSON *collageName = cJSON_GetObjectItemCaseSensitive(collage,"name");
    cJSON *slogan = cJSON_GetObjectItemCaseSensitive(collage,"slogan");
    cJSON *date = cJSON_GetObjectItemCaseSensitive(collage,"est");
    printf("\t\t\t\t%s",cJSON_GetStringValue(collageName));
    printf("\t\t\t   %s",cJSON_GetStringValue(slogan));
    printf("\t\t\t\t    %s",cJSON_GetStringValue(date));
  }
}
