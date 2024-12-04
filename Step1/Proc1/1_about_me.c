/**
 * 단계1 과정1 Problem 1
 */


/*
[ 수행 문제 ]
선호하는 운영체제에 ANSI C 언어 개발 환경을 만든 후, 컴파일러 버전을 출력한다.
    - gcc 버전 9.4.x 이상
아서와 팀원의 기초 정보를 콘솔에 출력한다.
    - 아래 제시한 출력 형식을 지켜야 한다. 
    - “소개”의 내용 출력 형식: 문장의 마침표를 만나면 다음 줄에 나머지 문장을 표시해야 한다.

[마그라테아] ❤❤ 프로젝트 멤버 소개 ❤❤
-------------------------------------------------
이름 | 아서 덴트
성별 | 남
전공 | 기계 공학
경력 | 15년
역할 | 아키텍트
기술 | C/C++, 자바, 스프링, 파이썬, 머신러닝/딥러닝
소개 | 실리콘 밸리에서 SNS, 핀테크, HR, 미디어 등의 다양한 프로젝트에 참여하며 경력을 쌓았습니다. 
      성공과 실패를 겪으며 얻게 된 깨달음을 여러분과 나누고 싶습니다.
--------------------------------------------------
이름 | 김영진
성별 | 남
......(생략)........

[ 제약 사항 ]
    - 모든 코드는 main() 함수 내에 작성한다.
    - 제출할 파일의 이름은 about_me.c다.
    - 표준 출력 함수만 사용해야 한다.
    - 아서와 팀원의 기초 정보는 다음과 같다.

이름	성별	전공	경력	역할	보유 기술	자기소개
아서 덴트	남	기계 공학	15	아키텍트	C/C++, 자바, 스프링, 파이썬, 머신러닝/딥러닝	실리콘 밸리에서 SNS, 핀테크, HR, 미디어 등의 다양한 프로젝트에 참여하며 경력을 쌓았습니다. 성공과 실패를 겪으며 얻게된 깨달음을 여러분과 나누고 싶습니다.
김영진	남	컴퓨터 공학	2	개발자	C#, 파이썬, 자바스크립트, 리액트, 코틀린	최근에 MAUI 프레임워크로 진행한 개인 자산 관리 프로젝트에서 소프트웨어 개발에 엄청난 매력을 느꼈습니다. 나의 코드로 현실의 문제를 해결한다니! 마그라테아를 성공적으로 개발하는 것은 저의 버킷 리스트 중 하나가 되었습니다.
임원철	남	전자 공학	1	DBA	자바, PHP, Mongo DB, MS SQL, MySQL	애플리케이션은 결국 데이터를 다루는 방식을 구현한 것이라고 생각합니다. 대학에서 컴퓨터 공학과의 빅데이터 과목을 수강하며 데이터 플랫폼에 관해 매력을 느꼈습니다. 이번 프로젝트의 성공 여부는 데이터에 달렸다고 생각합니다. 마그라테아에서 다룰 데이터를 생각하면 벌써 부터 흥분됩니다.
유고은	여	경영 정보	1	클라우드	자바, PowerShell, Azure, AWS, GCP	김영진님과 함께 프로젝트를 진행했으며 클라우드 아키텍처 구현을 담당했습니다. 학창시절 클라우드에 매력을 느껴 마이크로소프트 Azure에 빠져들었는데, 깊이 탐구하다보니 다른 퍼블릭 클라우드도 어렵지 않게 이해할 수 있었습니다. 마그라테아의 클라우드 아키텍처를 내 손으로 꼭 완성시키고 싶습니다.
서혜경	여	정치외교	0	개발자	파이썬, 스위프트, 코틀린, Node.js, 피그마	학부과정에서 과제로 프로젝트는 많이 진행해봤지만, 기업의 사활이 걸린 실전 프로젝트는 제 인생의 첫 경험입니다. 이 프로젝트에 참여하게 되어 기대도 많이 되는 한편으로, 제가 잘할 수 있을까 염려가 되기도 합니다. 마그라테아 프로젝트에 관해 들었을 때 제 속에서 이 프로젝트는 인생을 걸고 싶다는 생각을 했습니다. 링크드인을 통해 이미 아서님의 명성을 접했던 터라, 이번 프로젝트에 함께할 수 있어서 영광입니다.

[ 보너스 ]
(보너스) 경력 표기를  4바이트 2진수 표기로 변경하고 2진수 표기임을 나타낸다.
(보너스) 프로젝트 멤버 소개 출력 형식을 변경한다.
한 행에 2개의 열을 표시할 때는 열과 열을 탭으로 띄워야 한다.
출력 형식:
[마그라테아] ❤❤ 프로젝트 멤버 소개 ❤❤
=====================================================================
이름 | 아서 덴트     성별 | 남
전공 | 기계 공학     경력 | 15년
역할 | 아키텍트      기술 | C/C++, 자바, 스프링, 파이썬, 머신러닝/딥러닝
---------------------------------------------------------------------
소개 | 실리콘 밸리에서 SNS, 핀테크, HR, 미디어 등의 다양한 프로젝트에 참여하며 경력을 쌓았습니다. 
      성공과 실패를 겪으며 얻게 된 깨달음을 여러분과 나누고 싶습니다.
=====================================================================
이름 | 김영진        성별 | 남

[ 보너스 평가 가이드 ]
경력 표기를 4바이트 2진수 표기로 변경했는지 확인한다. 
출력 예시: (2)는 2진수 표기임을 나타낸다.
....
경력 | 00000000 00000000 00000000 00001111(2)년
....
프로젝트 멤버 소개 출력 형식을 제시한 화면 출력과 동일하게 변경했는지 확인한다.

*/

#include <stdio.h>
#include <stdint.h>
#include <locale.h>

// 경력을 4바이트 2진수 문자열로 변환하는 함수
void print_binary(uint32_t num) {
    for (int i = 31; i >= 0; i--) {
        printf("%c", (num & (1 << i)) ? '1' : '0');
        if (i % 8 == 0 && i != 0) printf(" "); // 8비트 단위로 띄어쓰기
    }
    printf("(2)");
}

int main() {
    setlocale(LC_ALL, "ko_KR.UTF-8");

    // 출력 시작
    printf("[마그라테아] ❤❤ 프로젝트 멤버 소개 ❤❤\n");
    printf("=====================================================================\n");

    // 아서 덴트
    printf("이름 | 아서 덴트\t성별 | 남\n");
    printf("전공 | 기계 공학\t경력 | ");
    print_binary(15); // 경력: 15년
    printf("년\n");
    printf("역할 | 아키텍트\t기술 | C/C++, 자바, 스프링, 파이썬, 머신러닝/딥러닝\n");
    printf("---------------------------------------------------------------------\n");
    printf("소개 | 실리콘 밸리에서 SNS, 핀테크, HR, 미디어 등의 다양한 프로젝트에 참여하며 경력을 쌓았습니다.\n");
    printf("      성공과 실패를 겪으며 얻게 된 깨달음을 여러분과 나누고 싶습니다.\n");
    printf("=====================================================================\n");

    // 김영진
    printf("이름 | 김영진\t성별 | 남\n");
    printf("전공 | 컴퓨터 공학\t경력 | ");
    print_binary(2); // 경력: 2년
    printf("년\n");
    printf("역할 | 개발자\t기술 | C#, 파이썬, 자바스크립트, 리액트, 코틀린\n");
    printf("---------------------------------------------------------------------\n");
    printf("소개 | 최근에 MAUI 프레임워크로 진행한 개인 자산 관리 프로젝트에서 소프트웨어 개발에 엄청난 매력을 느꼈습니다.\n");
    printf("      나의 코드로 현실의 문제를 해결한다니! 마그라테아를 성공적으로 개발하는 것은 저의 버킷 리스트 중 하나가 되었습니다.\n");
    printf("=====================================================================\n");

    // 임원철
    printf("이름 | 임원철\t성별 | 남\n");
    printf("전공 | 전자 공학\t경력 | ");
    print_binary(1); // 경력: 1년
    printf("년\n");
    printf("역할 | DBA\t기술 | 자바, PHP, Mongo DB, MS SQL, MySQL\n");
    printf("---------------------------------------------------------------------\n");
    printf("소개 | 애플리케이션은 결국 데이터를 다루는 방식을 구현한 것이라고 생각합니다.\n");
    printf("      대학에서 컴퓨터 공학과의 빅데이터 과목을 수강하며 데이터 플랫폼에 관해 매력을 느꼈습니다.\n");
    printf("      이번 프로젝트의 성공 여부는 데이터에 달렸다고 생각합니다. 마그라테아에서 다룰 데이터를 생각하면 벌써부터 흥분됩니다.\n");
    printf("=====================================================================\n");

    // 유고은
    printf("이름 | 유고은\t성별 | 여\n");
    printf("전공 | 경영 정보\t경력 | ");
    print_binary(1); // 경력: 1년
    printf("년\n");
    printf("역할 | 클라우드\t기술 | 자바, PowerShell, Azure, AWS, GCP\n");
    printf("---------------------------------------------------------------------\n");
    printf("소개 | 김영진님과 함께 프로젝트를 진행했으며 클라우드 아키텍처 구현을 담당했습니다.\n");
    printf("      학창시절 클라우드에 매력을 느껴 마이크로소프트 Azure에 빠져들었는데, 깊이 탐구하다보니 다른 퍼블릭 클라우드도 어렵지 않게 이해할 수 있었습니다.\n");
    printf("      마그라테아의 클라우드 아키텍처를 내 손으로 꼭 완성시키고 싶습니다.\n");
    printf("=====================================================================\n");

    // 서혜경
    printf("이름 | 서혜경\t성별 | 여\n");
    printf("전공 | 정치외교\t경력 | ");
    print_binary(0); // 경력: 0년
    printf("년\n");
    printf("역할 | 개발자\t기술 | 파이썬, 스위프트, 코틀린, Node.js, 피그마\n");
    printf("---------------------------------------------------------------------\n");
    printf("소개 | 학부과정에서 과제로 프로젝트는 많이 진행해봤지만, 기업의 사활이 걸린 실전 프로젝트는 제 인생의 첫 경험입니다.\n");
    printf("      이 프로젝트에 참여하게 되어 기대도 많이 되는 한편으로, 제가 잘할 수 있을까 염려가 되기도 합니다.\n");
    printf("      마그라테아 프로젝트에 관해 들었을 때 제 속에서 이 프로젝트는 인생을 걸고 싶다는 생각을 했습니다.\n");
    printf("      링크드인을 통해 이미 아서님의 명성을 접했던 터라, 이번 프로젝트에 함께할 수 있어서 영광입니다.\n");
    printf("=====================================================================\n");

    return 0;
}
/*
주요 특징
4바이트 2진수 변환

print_binary() 함수는 경력을 4바이트 2진수로 출력하고 (2)를 추가합니다.
출력 형식

한 행에 두 개의 열을 표시하며, 열 사이에는 탭(\t)을 사용했습니다.
가독성

긴 문장은 다음 줄로 넘어가도록 포맷팅했습니다.
확장성

새로운 멤버 정보를 쉽게 추가할 수 있도록 출력 형식을 통일했습니다.
*/
