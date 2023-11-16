#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// 구조체를 사용하여 개개인의 정보를 저장
struct Person {
    char name[50];
    char gender;
    char major[50];
};

int main() {
    // 난수 생성기 초기화
    srand(time(NULL));

    // 전체 인원 수 total_n 설정 (지원자 수)
    int total_people = *tatal_n*;

    // n명짜리 팀 생성
    int team_size = *n*;

    // 전체 사람들의 정보 저장
    struct Person people[*total_n*];

    // 사용자로부터 이름, 성별, 전공 입력
    for (int i = 0; i < total_people; i++) {
        printf("이름을 입력하세요: ");
        scanf("%s", people[i].name);

        printf("성별을 입력하세요 (남자: M, 여자: F): ");
        scanf(" %c", &people[i].gender);

        printf("전공을 입력하세요 (예술: A, 일반: G): ");
        scanf(" %s", people[i].major);
    }

    // 성비와 전공 비율이 1:1인 팀 생성
    struct Person team[12];

    int male_count = 0;
    int female_count = 0;
    int art_major_count = 0;
    int general_major_count = 0;

    for (int i = 0; i < 12; i++) {
        int random_index;
        do {
            random_index = rand() % total_people;
        } while (
            (people[random_index].gender == 'M' && male_count >= team_size / 2) ||
            (people[random_index].gender == 'F' && female_count >= team_size / 2) ||
            (strcmp(people[random_index].major, "A") == 0 && art_major_count >= team_size / 2) ||
            (strcmp(people[random_index].major, "G") == 0 && general_major_count >= team_size / 2)
            );

        strcpy(team[i].name, people[random_index].name);
        team[i].gender = people[random_index].gender;
        strcpy(team[i].major, people[random_index].major);

        // 성비 및 전공 비율 업데이트
        if (team[i].gender == 'M') {
            male_count++;
        }
        else if (team[i].gender == 'F') {
            female_count++;
        }
        if (strcmp(team[i].major, "A") == 0) {
            art_major_count++;
        }
        else if (strcmp(team[i].major, "G") == 0) {
            general_major_count++;
        }
    }

    // 결과 출력
    printf("성비와 전공 비율이 1:1인 팀 구성원:\n");
    for (int i = 0; i < team_size; i++) {
        printf("이름: %s, 성별: %c, 전공: %s\n", team[i].name, team[i].gender, team[i].major);
    }

    return 0;
}
