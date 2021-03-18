#include <stdio.h>
#include <stdlib.h>
void clear();
double culc();
/*
--넣을 기능--
원금, 이자율, 횟수를 넣고 이자금을 출력
log를 남겨서 각 횟수마다 [단일 이자],[이자의 합],[원금+총이자]출력
+숫자에 쉼표 찍기

*/

int main(void) {
  double p,i;
  int n;
  clear();
  printf("##------------------------------##\n");
  printf("##----------복리계산기----------##\n");
  printf("##------------------------------##\n");
  printf("> 원금을 입력하십시오\n");
  scanf("%lf", &p);
  printf("> 이자율을 입력하십시오(%로)\n");
  scanf("%lf", &i);
  printf("> 이자가 붙는 횟수(기간)를 입력하십시오(정수로)\n");
  scanf("%d", &n);
  culc(p, i/100, n);
  return 0;
}

double culc(double principal, double per, int num){
  double log[3][20];
  double PnI;
  log[0][0] = per*principal;//단일 이자
  log[1][0] = 0;//이자 총합
  log[2][0] = principal;//원금+총이자
  printf("----------원금-----------\n");
    printf("단일이자 %.1f\n",log[0][0]);
    printf("이자총합%.1f\n",log[1][0]);
    printf("원금%.1f\n",log[2][0]);
  for(int i=1;i<num+1;i++){
    printf("----------%d회-----------\n",i);
    log[0][i] = log[2][i-1]*per;
    printf("단일이자 %.1f\n",log[0][i]);
    log[1][i] = (log[2][i-1]*per) + log[1][i-1];
    printf("이자총합%.1f\n",log[1][i]);
    log[2][i] = log[2][i-1]*per + log[2][i-1];
    printf("총액수(원리금)%.1f\n",log[2][i]);
  }
}

void clear(){
  //화면 지우는 함수. 윈도우면 clear 대신 cls를 입력력
  printf("\n");
  system("clear");
}
