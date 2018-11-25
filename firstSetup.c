#include "headers/firstSetup.h"
#include<stdio.h>
#include<stdlib.h>
#include "headers/cJSON.h"

cJSON *data = NULL;
cJSON *collage = NULL;
cJSON *students = NULL;

void setup(){
  data = cJSON_CreateObject();
  cJSON_AddItemToObject(data,"collage",collage=cJSON_CreateObject());
  cJSON_AddItemToObject(data,"students",students = cJSON_CreateObject());

}

int fileExist(const char * filename){
  FILE *file;
  if(file = fopen(filename,"r")){
    fclose(file);
    return 1;
  }
  return 0;
}

void createFile(char *filename){
      FILE *file;

      char collageName[30];
      char slogan[50];
      char date[4];
      printf("%s\n","Enter the name of your collage.");
      fgets(collageName,100,stdin);
      printf("%s\n","Enter a collage slogan" );
      fgets(slogan,100,stdin);
      printf("%s\n","Enter the establish date");
      fgets(date,100,stdin);

      cJSON_AddItemToObject(collage,"slogan",cJSON_CreateString(slogan));
      cJSON_AddItemToObject(collage,"name",cJSON_CreateString(collageName));
      cJSON_AddItemToObject(collage,"est",cJSON_CreateString(date));
      file = fopen("data.json","w");
      fputs(cJSON_Print(data),file);
      printf("%s\n",cJSON_Print(data));

}
