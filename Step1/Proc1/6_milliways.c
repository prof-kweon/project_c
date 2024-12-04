/*
 * 단계1 과정1 Problem 6
 */


/*
수행 문제
문제 3의 후보자 6명의 데이터(소개는 제외)에 후보자 고유 ID(문제 5에서 생성), 합격 여부가 포함된 JSON 형식의 문자열을 담은 배열 candidate##_arr로 작성한다.
candidate##_arr에서 합격한 멤버에 대해 아래 제약 사항의 추가 데이터에 관해 인터뷰하는 코드를 작성한다. 이 때 for 반복문을 사용한다. 
candidate##_arr에서 합격자의 기존 기초 정보를 복사해 새로운 milliways##_arr 배열에 복사하고, 인터뷰를 통해 수집된 정보를 추가 한다. 
추가 데이터 중 몸무게는 키와 BMI 값으로 계산하여 채운다.
milliways##_arr 내용을 리스트 형식으로 출력한다.
(보너스) milliways##_arr 내용을 리스트 형식으로 출력할 때 BMI 값에 따라 저체중, 정상, 과체중, 비만을 표시한다.

제약 사항
밀리웨이즈의 정규 멤버 4인의 기초 데이터는 문제 3의 후보자 데이터 외에 다음의 데이터가 추가되었다.
이름	닉네임	학력	키	몸무게	혈액형	알러지	취미	SNS
박지연	Ariel	고1중퇴	168cm		A	유제품	댄스 연습, 작곡	Instagram - @Ariel_Jiyeon
Ethan Smith	Simba	중3중퇴	178cm		O	땅콩	노래 작곡, 헬스 트레이닝	Twitter - @Simba_Ethan
Helena Silva	Belle	중졸	163cm		B	생선	노래 부르기, 그림 그리기	Instagram - @Belle_Helena
Liam Wilson	Aladdin	중2중퇴	175cm		AB	갑각류	춤추기, 음악 프로듀싱	Instagram - @Aladdin_Liam
코드는 milliways.c 파일에 작성한다.
문제 3과 문제 5의 데이터를 사용한다.
키의 단위는 m, 몸무게의 단위는 kg, 생년월일은 8자리 정수를 사용한다 
(해당 데이터 속성은 모두 소문자 영어 키워드를 사용한다.)
코드에서 사용하는 모든 배열은 1 차원이다.
표준 라이브러리는 stdio.h와 stdlib.h만 사용한다.
보너스 평가 가이드
milliways##_arr 내용을 리스트 형식으로 출력할 때 BMI 값에 따라 메시지를 표시하는지 확인한다.
switch 문을 사용해 구현했는지 확인한다. 
저체중, 정상, 과체중, 비만의 4가지 값으로 표시하는지 확인 한다. 
*/

#include <stdio.h>
#include <stdlib.h>
// #include <string.h>

#define MAX_MEMBERS 4
#define MAX_BUFFER 256

// 구조체 정의
typedef struct {
    char name[50];
    int id;
    char nickname[20];
    char education[20];
    float height; // in meters
    float weight; // in kg
    char blood_type[3];
    char allergy[50];
    char hobbies[100];
    char sns[100];
    float bmi; // Calculated BMI
} Member;

// 후보자 배열 초기화
const char candidate_arr[MAX_MEMBERS][MAX_BUFFER] = {
    "{\"name\":\"박지연\",\"id\":123456,\"height\":1.68,\"bmi\":18.5}",
    "{\"name\":\"Ethan Smith\",\"id\":234567,\"height\":1.78,\"bmi\":21.2}",
    "{\"name\":\"Helena Silva\",\"id\":345678,\"height\":1.63,\"bmi\":20.8}",
    "{\"name\":\"Liam Wilson\",\"id\":456789,\"height\":1.75,\"bmi\":20.1}"
};

// 밀리웨이즈 멤버 배열
Member milliways_arr[MAX_MEMBERS];

// BMI 상태 메시지 출력
const char *bmi_status(float bmi) {
    switch ((int)bmi) {
        case 0 ... 18: // // note: cannot omit the space between 1000 and ...
            return "저체중";
        case 19 ... 24:
            return "정상";
        case 25 ... 29:
            return "과체중";
        default:
            return "비만";
    }
}

// 몸무게 계산 함수
float calculate_weight(float height, float bmi) {
    return bmi * (height * height);
}

// JSON 데이터 파싱 및 milliways 배열 초기화
void parse_candidates() {
    for (int i = 0; i < MAX_MEMBERS; i++) {
        sscanf(candidate_arr[i],
               "{\"name\":\"%[^\"]\",\"id\":%d,\"height\":%f,\"bmi\":%f}",
               milliways_arr[i].name,
               &milliways_arr[i].id,
               &milliways_arr[i].height,
               &milliways_arr[i].bmi);
    }
}

// 인터뷰 데이터 입력
void collect_interview_data() {
    for (int i = 0; i < MAX_MEMBERS; i++) {
        printf("\n[%d] %s의 추가 정보를 입력하세요.\n", i + 1, milliways_arr[i].name);
        printf("닉네임: ");
        scanf("%s", milliways_arr[i].nickname);

        printf("학력: ");
        scanf("%s", milliways_arr[i].education);

        printf("혈액형: ");
        scanf("%s", milliways_arr[i].blood_type);

        printf("알러지: ");
        scanf(" %[^\n]", milliways_arr[i].allergy);

        printf("취미: ");
        scanf(" %[^\n]", milliways_arr[i].hobbies);

        printf("SNS: ");
        scanf(" %[^\n]", milliways_arr[i].sns);

        // 몸무게 계산
        milliways_arr[i].weight = calculate_weight(milliways_arr[i].height, milliways_arr[i].bmi);
    }
}

// 밀리웨이즈 멤버 출력
void print_milliways_members() {
    printf("\n#######################################\n");
    printf("# 밀리웨이즈 최종 멤버 리스트           #\n");
    printf("#######################################\n");

    for (int i = 0; i < MAX_MEMBERS; i++) {
        printf("\n[%d] %s\n", i + 1, milliways_arr[i].name);
        printf("닉네임: %s\n", milliways_arr[i].nickname);
        printf("학력: %s\n", milliways_arr[i].education);
        printf("키: %.2fm\n", milliways_arr[i].height);
        printf("몸무게: %.2fkg\n", milliways_arr[i].weight);
        printf("혈액형: %s\n", milliways_arr[i].blood_type);
        printf("알러지: %s\n", milliways_arr[i].allergy);
        printf("취미: %s\n", milliways_arr[i].hobbies);
        printf("SNS: %s\n", milliways_arr[i].sns);
        printf("BMI: %.1f (%s)\n", milliways_arr[i].bmi, bmi_status(milliways_arr[i].bmi));
    }
}

int main() {
    // JSON 데이터 파싱
    parse_candidates();

    // 추가 데이터 인터뷰 수집
    collect_interview_data();

    // 최종 멤버 출력
    print_milliways_members();

    return 0;
}

/*
코드 설명
구조체 정의:

Member 구조체에 후보자의 모든 데이터를 저장하며, JSON 데이터에서 파싱한 값을 저장하고 인터뷰로 입력받은 데이터를 추가합니다.
JSON 데이터 파싱:

parse_candidates 함수에서 sscanf를 사용하여 candidate_arr의 JSON 문자열 데이터를 파싱해 구조체 배열에 저장합니다.
BMI 상태 메시지:

bmi_status 함수는 switch문을 사용해 BMI 값을 기반으로 저체중, 정상, 과체중, 비만을 반환합니다.
몸무게 계산:

calculate_weight 함수에서 BMI와 키를 사용하여 몸무게를 계산합니다.
인터뷰 데이터 입력:

collect_interview_data 함수에서 사용자 입력을 받아 추가 데이터를 milliways_arr에 저장합니다.
멤버 데이터 출력:

print_milliways_members 함수에서 모든 데이터를 리스트 형식으로 출력하며, BMI 상태 메시지도 함께 출력합니다.

*/