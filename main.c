#include <stdio.h>
#include <stdlib.h>
#include "test.h"//replit에서의 사용자 정의 헤더
void clear();
double culc();
/*
--넣을 기능--
원금, 이자율, 횟수를 넣고 이자금을 출력
log를 남겨서 각 횟수마다 [단일 이자],[이자의 합],[원금+총이자]출력
+숫자에 쉼표 찍기
뒤가 0인 소수점 버리기
버튼 누르면 횟수 즉시 한번 추가해서 출력

*/

int main(void) {
  for (int loop=1;loop ==1;){//다시하기용 전체 루프
  double p,i;
  int n;
  char loop_yn;
  clear();
  test();

  printf("##------------------------------##\n");
  printf("##----------복리계산기----------##\n");
  printf("##------------------------------##\n");
  printf("> 원금을 입력하십시오\n");
  scanf("%lf", &p);//double형 입력에는 lf씀
  printf("> 이자율을 입력하십시오(%로)\n");
  scanf("%lf", &i);
  printf("> 이자가 붙는 횟수(기간)를 입력하십시오(정수로)\n");
  scanf("%d", &n);
  culc(p, i/100, n);
  printf("> 다시 시작하려면 y, 끝내려면 n을 입력하십시오\n");

  for (;loop_yn!='y'&&loop_yn!='n';){//다시하기 선택
    scanf("%c", &loop_yn);
    if (loop_yn=='y'){
      loop=1;
    }
    else if (loop_yn=='n'){
      loop=0;
      clear();
    }
    else {
    printf("y 또는 n을 입력해 주십시오\n");
    loop='x';
    }
  }
  loop_yn='x';
  }
  return 0;
}

double culc(double principal, double per, int num){
  double log[3][100];
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
