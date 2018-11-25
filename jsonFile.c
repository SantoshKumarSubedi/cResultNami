
#include<stdio.h>
#include "headers/cJSON.h"

void main(){
  printf("%s\n","This is for json testing" );

  cJSON *data = NULL;
  cJSON *collage = NULL;
  cJSON *students = NULL;
  int i = 0;

  data = cJSON_CreateObject();
  cJSON_AddItemToObject(data,"collage",collage=cJSON_CreateObject());
  cJSON_AddItemToObject(data,"students",students = cJSON_CreateObject());
  FILE *file;
  file = fopen("data.json","w");
  fputs(cJSON_Print(data),file);
  printf("%s\n",cJSON_Print(data));
}
