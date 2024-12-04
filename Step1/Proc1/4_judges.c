/**
 * 단계1 과정1 Problem 4
 */


/*
수행 문제
프로그램을 실행하면 다음의 화면에서 참여할 프로젝트와 총 심사위원 인원을 지정하고 심사위원 정보 입력을 시작한다.
####################################
#      심사위원 명단 데이터 입력       #
####################################
> 참여 프로젝트: 밀리웨이즈
> 심사 총 인원: 5
> 선발 멤버 수: 4
++++++++++++++++++++++++++++++++++++
5명의 심사위원 정보 입력을 시작합니다.
++++++++++++++++++++++++++++++++++++
*심사위원 1: "이름:김영수,성별:남,소속:JYK 스튜디오,직함:음악 감독 및 프로듀서,전문분야:음악,메일:youngsu@outlook.com,전화:010-1234-5678"
*심사위원 2: ..... 이하 생략 ..........
....................................
++++++++++++++++++++++++++++++++++++
심사위원 정보 입력이 끝났습니다.
++++++++++++++++++++++++++++++++++++
“심사위원 정보를 확인할까요?” 메시지를 출력하고  ‘Y’나 ‘N’ 문자(대문자)를 입력 받아, N이면 프로그램을 종료하고 Y이면 다음과 같이 출력한다. 
배열 요소에 들어간 문자열 데이터를 파싱해서 표시한다.
[PROJECT] 자리 표시자에 입력 받은 참여할 프로젝트 정보를 표시한다. 
[PROJECT] 심사위원 정보를 확인할까요? Y
####################################
#        심사위원 데이터 출력        #
####################################
[심사위원 1]
이름:김영수
성별:남
소속:JYK 스튜디오
직함:음악 감독 및 프로듀서
전문분야:음악
메일:youngsu@outlook.com
전화:010-1234-5678
-----------------------------------
[심사위원 2] 
...............이하 생략............
(보너스) 총 심사위원 기초 정보의 항목 수와 입력 정보 항목 수가 다른 경우 메시지를 출력하도록 개선한다.
- 메시지: “입력 항목이 정확하지 않습니다. 다시 입력해주세요.”

제약 사항
솔루션 코드는 judges.c 파일에 작성한다.
총 심사인원은 1 차원 배열 하나로 관리하며, 배열 요소 하나에 완전한 심사위원 데이터를 JSON 형식으로 저장한다. 심사위원 배열 이름은 judges_array이다.
표준 라이브러리는 stdio.h와 stdlib.h만 사용한다. 
총 심사위원 입력 화면은 무한 루프 while 반복문을 사용하고 지정한 심사위원 인원이 다 채워지면 무한 루프를 종료한다.
총 심사위원 정보 입력을 누락했는지 여부를 체크하고 다시 입력하도록 해야 한다. 
Cody Enter의 심사위원 기초 정보는 다음과 같다.
이름	성별	소속	직함	전문 분야	메일	전화
김영수	남	JYK 스튜디오	음악 감독 및 프로듀서	음악	youngsu@outlook.com	010-1234-5678
이지영	여	DK 엔터테인먼트	댄스 감독	댄스	jiyounghere@outlook.com	010-2345-6789
박민준	남	JM 엔터테인먼트	보컬 감독	보컬	minjun@outlook.com	010-3456-7890
송현우	남	Starlight Entertainment	비주얼 디렉터	비주얼	hyunwoo@outlook.com	010-4567-8901
박지영	여	음악평론가 협회	음악 평론가	음악 평론	jiyoung@outlook.com	010-5678-9012

*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_JUDGES 100
#define BUFFER_SIZE 512

// 심사위원 정보 배열
char judges_array[MAX_JUDGES][BUFFER_SIZE];

// JSON 데이터를 파싱하여 출력하는 함수
void parse_and_print_judge(int index, const char *data) {
    printf("[심사위원 %d]\n", index + 1);

    int i = 0, key_start = 0, value_start = 0;
    int in_key = 1; // Parsing key or value
    while (data[i] != '\0') {
        if (data[i] == ':') {
            // Key ends, Value starts
            printf("%.*s: ", i - key_start, &data[key_start]);
            value_start = i + 1;
            in_key = 0;
        } else if (data[i] == ',' || data[i + 1] == '\0') {
            // Value ends
            if (data[i + 1] == '\0') i++; // Include last character
            printf("%.*s\n", i - value_start, &data[value_start]);
            key_start = i + 1;
            in_key = 1;
        }
        i++;
    }
    printf("-----------------------------------\n");
}

// Custom implementation of strcspn
size_t custom_strcspn(const char *str, const char *delim) {
    size_t i = 0;
    while (str[i] != '\0') {
        const char *d = delim;
        while (*d != '\0') {
            if (str[i] == *d) {
                return i; // Found a delimiter character
            }
            d++;
        }
        i++;
    }
    return i; // No delimiter found
}

int main() {
    int total_judges = 0;
    int selected_members = 0;
    char project_name[100];
    char input[BUFFER_SIZE];
    char choice;

    // 프로젝트 이름 및 심사위원 인원 입력
    printf("####################################\n");
    printf("#      심사위원 명단 데이터 입력       #\n");
    printf("####################################\n");
    printf("> 참여 프로젝트: ");
    fgets(project_name, sizeof(project_name), stdin);
    project_name[custom_strcspn(project_name, "\n")] = '\0'; // 개행 문자 제거

    printf("> 심사 총 인원: ");
    scanf("%d", &total_judges);
    getchar(); // Flush newline

    printf("> 선발 멤버 수: ");
    scanf("%d", &selected_members);
    getchar(); // Flush newline

    printf("++++++++++++++++++++++++++++++++++++\n");
    printf("%d명의 심사위원 정보 입력을 시작합니다.\n", total_judges);
    printf("++++++++++++++++++++++++++++++++++++\n");

    int i = 0;
    while (i < total_judges) {
        printf("* 심사위원 %d: ", i + 1);
        fgets(input, sizeof(input), stdin);
        input[custom_strcspn(input, "\n")] = '\0'; // Remove trailing newline

        // 항목 개수 검증
        int comma_count = 0;
        for (int j = 0; input[j] != '\0'; j++) {
            if (input[j] == ',') comma_count++;
        }

        if (comma_count != 6) { // 7개의 데이터 항목이어야 함
            printf("입력 항목이 정확하지 않습니다. 다시 입력해주세요.\n");
            continue;
        }

        // 데이터 저장
        snprintf(judges_array[i], BUFFER_SIZE, "%s", input);
        i++;
    }

    printf("++++++++++++++++++++++++++++++++++++\n");
    printf("심사위원 정보 입력이 끝났습니다.\n");
    printf("++++++++++++++++++++++++++++++++++++\n");

    // 확인 여부
    printf("\"심사위원 정보를 확인할까요?\" (Y/N): ");
    scanf(" %c", &choice);

    if (choice == 'N') {
        printf("프로그램을 종료합니다.\n");
        return 0;
    }

    // 심사위원 정보 출력
    printf("\n####################################\n");
    printf("#        심사위원 데이터 출력        #\n");
    printf("####################################\n");

    for (int j = 0; j < total_judges; j++) {
        parse_and_print_judge(j, judges_array[j]);
    }

    return 0;
}

/*
코드 설명
심사위원 정보 배열

judges_array는 각 심사위원 데이터를 JSON 형식으로 저장하는 1차원 배열입니다.
배열 요소 하나당 한 명의 심사위원 정보를 포함합니다.
데이터 입력

fgets를 사용하여 JSON 형식으로 데이터를 입력받습니다.
콤마(,) 개수를 세어 항목 개수를 검증합니다. 올바르지 않은 경우 다시 입력을 요청합니다.
데이터 파싱

parse_and_print_judge 함수는 JSON 데이터를 키(key)와 값(value)으로 분리하여 출력합니다.
:를 기준으로 키와 값을 나누고, ,를 기준으로 항목을 구분합니다.
출력

사용자가 Y를 입력하면 입력된 데이터를 출력하며, 각 심사위원 데이터를 보기 좋게 포맷팅합니다.
제약 조건 충족

stdio.h와 stdlib.h만 사용하며, 모든 요구 사항을 만족합니다.
*/