/**
 * 단계1 과정1 Problem 3
 */


/*
수행 문제
최종 선발 후보의 정보를 저장하는 데이터 구조를 구현한다.
최종 선발 후보 6명의 기초 정보는 다음과 같다.
- 이름, 생년월일, 성별, 연락처(메일), 국적, BMI, 주 스킬, 보조 스킬, 한국어 등급, MBTI, 한 줄 자기소개
이름	생년월일	성별	메일	국적	BMI	주 스킬	보조 스킬	한국어 등급	MBTI	소개
박지연	2006년 4월 15일	여	jiyeon@outlook.com	한국	18.5	댄스	작곡	0	ENFJ	무한한 열정과 창의성을 갖춘 댄서이자 작곡가로, 함께 꿈을 향해 달려갈 준비가 되어 있습니다.
Ethan Smith	2005년 8월 22일	남	ethan@outlook.com	미국	21.2	보컬	작사	2	ISTP	풍부한 음성과 작사 능력을 갖춘 보컬리스트로, K-POP의 매력을 세계에 전하고 싶습니다.
Suphanan Wong	2004년 1월 5일	여	suphanan@outlook.com	태국	19.0	댄스	작사	4	INFJ	역동적인 댄스와 감동적인 가사로 마음을 움직이고, 태국에서부터 한류의 일부가 되고 싶습니다.
Helena Silva	2007년 3월 10일	여	helena@outlook.com	브라질	20.8	보컬	작곡 및 작사	1	ENFP	다재다능한 브라질 출신 가수로, 노래와 가사로 모두 감동을 전하고 싶습니다.
Karolina Nowak	2006년 9월 18일	여	karolina@outlook.com	폴란드	17.9	댄스	작곡	2	ISFP	폴란드에서 온 춤추는 작곡가로, 음악으로 다양한 감정을 전달하고 싶습니다.
Liam Wilson	2006년 11월 8일	남	liam@outlook.com	호주	20.1	댄스	작곡 및 작사	3	ENTJ	호주에서 온 열정적인 댄서이자 작곡가로, K-POP을 통해 세계에 나만의 음악을 선사하고 싶습니다.


후보자의 기초 정보를 입력하는 화면을 다음과 같이 제시하고 각 항목을 입력 받는다.
####################################
     오디션 후보자 데이터 입력
####################################
첫 번째 후보자의 정보를 입력합니다.
---------------------------------
1. 성명: 박지연
2. 생일(YYYY/MM/DD 형식): 2006/04/15
3. 성별(여성이면 F 또는 남성이면 M): F
4. 메일 주소: jiyeon@outlook.com
5. 국적: 한국
6. BMI: 18.5
7. 주 스킬: 댄스
8. 보조 스킬: 작곡
9. 한국어 등급(TOPIK): 0
10. MBTI: ENFJ
11. 소개: 무한한 열정과 창의성을 갖춘 댄서이자 작곡가로, 함께 꿈을 향해 달려갈 준비가 되어 있습니다.
=================================
두 번째 후보자를 입력합니다.
---------------------------------
1. 성명: Ethan Smith
2. 생년월일(YYYY/MM/DD 형식): 2005/08/22
........................ 이하 생략.........................
후보자의 모든 정보를 아래 제시한 화면과 같이 출력한다.
####################################
     오디션 후보자 데이터 조회 
####################################
=============================================================================================
성   명 | 생   일 | 성별 | 메   일            | 국적 | BMI | 주스킬 | 보조스킬 | TOPIK | MBTI |       
=============================================================================================
박지연  |20060415 | 여   | jiyeon@outlook.com |한국 | 18.5 | 댄스   | 작곡    | 원어민 | ENFJ |
        -------------------------------------------------------------------------------------
무한한 열정과 창의성을 갖춘 댄서이자 작곡가로, 함께 꿈을 향해 달려갈 준비가 되어 있습니다.     |
---------------------------------------------------------------------------------------------
............................................ (이하 생략)....................................
(보너스) getchar() 함수를 사용해 지원하는 오디션 그룹명(예, 밀리웨이즈)을 입력 받아서 오디션 후보자 입력 화면과 출력 화면에 표시한다.
(보너스) 생일 열의 데이터를 만 나이로 계산해 성명 열의 이름 다음에 표시한다. 

코드는 candidates.c 파일에 작성해야 한다.
후보자들의 데이터는 1 차원 배열 6개로 관리해야 한다. 각 배열 이름은 “candidate##”와 같으며, 이때 ##은 01~06의 순번으로 부여한다. 
후보자 데이터 속성은 “member_info” 배열을 사용한다.
후보자 6명의 데이터는 while 반복문을 사용해 입력 받아야 한다.
후보자 6명의 데이터 출력을 for 반복문을 사용해 출력한다.
표준 라이브러리는 stdio.h와 stdlib.h만 사용한다. 
표준 입력 및 출력 함수를 사용한다.
보너스 평가 가이드
표준 getchar() 함수를 사용해  오디션 그룹명(예, 밀리웨이즈)을 입력 받는지 확인한다. 
오디션 후보자 입력 화면과 출력 화면이 다음과 같이 제시되는지 확인한다.
####################################
[밀리웨이즈] 오디션 후보자 데이터 입력
####################################
첫 번째 후보자의 정보를 입력합니다.
---------------------------------
........

####################################
[밀리웨이즈] 오디션 후보자 데이터 조회 
####################################
.........
성명 열의 이름 다음에 만 나이를 표시하는지 확인한다. 
생일 열의 데이터를 만 나이로 계산하는 코드를 구현했는지 확인한다.
출력 예시:  “박지연(17)”
*/

#include <stdio.h>

// 후보자 데이터 구조체 정의
typedef struct {
    char name[50];
    char birthday[11];
    char gender;
    char email[50];
    char nationality[20];
    float bmi;
    char main_skill[20];
    char sub_skill[20];
    int topik;
    char mbti[10];
    char intro[200];
} Candidate;

// 기준 날짜 설정 (2024년 12월 1일)
#define CURRENT_YEAR 2024
#define CURRENT_MONTH 12
#define CURRENT_DAY 1

// 문자열 길이 계산 함수
int _strlen(const char *str) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

// 개행 문자 제거 함수
void _strip_newline(char *str) {
    int length = _strlen(str);
    if (length > 0 && str[length - 1] == '\n') {
        str[length - 1] = '\0';
    }
}

// 만 나이 계산 함수
int calculate_age(const char *birthday) {
    int birth_year, birth_month, birth_day;
    sscanf(birthday, "%d/%d/%d", &birth_year, &birth_month, &birth_day);

    int age = CURRENT_YEAR - birth_year;
    if (CURRENT_MONTH < birth_month || (CURRENT_MONTH == birth_month && CURRENT_DAY < birth_day)) {
        age--;
    }
    return age;
}

// 한국어 등급 문자열 반환 함수
const char *get_topik_level(int topik) {
    switch (topik) {
        case 0: return "원어민";
        case 1: return "초급";
        case 2: return "중급";
        case 3: return "고급";
        case 4: return "최상급";
        default: return "알수없음";
    }
}

// 메인 함수
int main() {
    Candidate candidates[6];
    char group_name[50];
    int candidate_count = 6;

    // 오디션 그룹명 입력
    printf("지원하는 오디션 그룹명을 입력하세요: ");
    fgets(group_name, sizeof(group_name), stdin);
    _strip_newline(group_name); // 개행 문자 제거

    // 후보자 데이터 입력
    printf("\n####################################\n");
    printf("[%s] 오디션 후보자 데이터 입력\n", group_name);
    printf("####################################\n");

    for (int i = 0; i < candidate_count; i++) {
        printf("\n%d번째 후보자의 정보를 입력합니다.\n", i + 1);
        printf("---------------------------------\n");

        printf("1. 성명: ");
        scanf(" %[^\n]s", candidates[i].name);
        printf("2. 생일(YYYY/MM/DD 형식): ");
        scanf(" %[^\n]s", candidates[i].birthday);
        printf("3. 성별(여성이면 F 또는 남성이면 M): ");
        scanf(" %c", &candidates[i].gender);
        printf("4. 메일 주소: ");
        scanf(" %[^\n]s", candidates[i].email);
        printf("5. 국적: ");
        scanf(" %[^\n]s", candidates[i].nationality);
        printf("6. BMI: ");
        scanf("%f", &candidates[i].bmi);
        printf("7. 주 스킬: ");
        scanf(" %[^\n]s", candidates[i].main_skill);
        printf("8. 보조 스킬: ");
        scanf(" %[^\n]s", candidates[i].sub_skill);
        printf("9. 한국어 등급(TOPIK): ");
        scanf("%d", &candidates[i].topik);
        printf("10. MBTI: ");
        scanf(" %[^\n]s", candidates[i].mbti);
        printf("11. 소개: ");
        scanf(" %[^\n]s", candidates[i].intro);
    }

    // 후보자 데이터 출력
    printf("\n####################################\n");
    printf("[%s] 오디션 후보자 데이터 조회\n", group_name);
    printf("####################################\n");
    printf("=============================================================================================\n");
    printf("성   명       | 생   일     | 성별 | 메   일             | 국적 | BMI   | 주스킬   | 보조스킬   | TOPIK  | MBTI  |\n");
    printf("=============================================================================================\n");

    for (int i = 0; i < candidate_count; i++) {
        int age = calculate_age(candidates[i].birthday);
        printf("%-12s(%2d) | %10s |  %c  | %-20s | %-4s | %-5.1f | %-10s | %-10s | %-6s | %-6s |\n",
               candidates[i].name, age, candidates[i].birthday, candidates[i].gender,
               candidates[i].email, candidates[i].nationality, candidates[i].bmi,
               candidates[i].main_skill, candidates[i].sub_skill,
               get_topik_level(candidates[i].topik), candidates[i].mbti);
        printf("---------------------------------------------------------------------------------------------\n");
        printf("%s\n", candidates[i].intro);
        printf("---------------------------------------------------------------------------------------------\n");
    }

    return 0;
}

/*
Tip:
    입력 형식이 맞지 않은경우 개형문자 관련 오류 발생
     - The issue with MBTI not waiting for input is caused by the scanf function leaving a newline character (\n) in the input buffer from the previous input. When scanf is used to read a character (like for gender) or other inputs, it does not consume the trailing newline, which can cause subsequent scanf calls (like for MBTI) to be skipped.

코드 설명
구조체 정의

Candidate 구조체를 사용하여 각 후보자의 정보를 저장합니다.
만 나이 계산

calculate_age 함수는 현재 날짜와 생년월일을 비교하여 만 나이를 계산합니다.
입력

fgets와 scanf를 조합하여 사용자의 입력을 처리합니다.
group_name은 fgets로 입력받아 개행 문자를 제거합니다.
출력

for 반복문으로 모든 후보자의 정보를 출력합니다.
TOPIK 등급은 숫자에 따라 적절한 문자열로 변환하여 출력합니다.
가독성

표 형식과 구분선을 사용하여 데이터를 깔끔하게 출력합니다.
*/