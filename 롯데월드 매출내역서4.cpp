#include <stdio.h>

const int MAX=100;
int year[MAX],month[MAX],day[MAX],
	ticketType[MAX],ticketTime[MAX],ageGroup[MAX],
	count[MAX],ticketPrice[MAX],discountType[MAX];
int index=0, k=0;
int type[4][7]={0};//권종별 
int time[MAX][4]={0};//날짜별 
int com[7]={0};//우대별 

void readReport() {
	FILE *fp =fopen("report.csv", "r");
	while(fscanf(fp,"%d,%d,%d,%d,%d,%d,%d,%d,%d",&year[index],&month[index],&day[index],
					&ticketType[index],&ticketTime[index],&ageGroup[index],&count[index],
					&ticketPrice[index],&discountType[index]) != -1){
		index++;
	}
	fclose(fp);
}

void printReport() {
	for (int i=0;i<index;i++){
		printf("%d,%d,%d,%d,%d,%d,%d,%d,%d\n",year[i],month[i],day[i],
					ticketType[i],ticketTime[i],ageGroup[i],count[i],
					ticketPrice[i],discountType[i]);
	}
	printf("\n\n");
}

void kindOfTicket() {
	for (int i=0;i<index;i++){
		if (ticketType[i]==1 && ticketTime[i]==1){
			type[0][0]+=count[i];
			type[0][6]+=ticketPrice[i];
			switch (ageGroup[i]){
				case 1:
					type[0][1]+=count[i];
					break;
				case 2:
					type[0][2]+=count[i];
					break;
				case 3:
					type[0][3]+=count[i];
					break;
				case 4:
					type[0][4]+=count[i];
					break;
				case 5:
					type[0][5]+=count[i];
					break;
			}
		}
		else if (ticketType[i]==1 && ticketTime[i]==2){
			type[1][0]+=count[i];
			type[1][6]+=ticketPrice[i];
			switch (ageGroup[i]){
				case 1:
					type[1][1]+=count[i];
					break;
				case 2:
					type[1][2]+=count[i];
					break;
				case 3:
					type[1][3]+=count[i];
					break;
				case 4:
					type[1][4]+=count[i];
					break;
				case 5:
					type[1][5]+=count[i];
					break;
			}
		}
		else if (ticketType[i]==2 && ticketTime[i]==1){
			type[2][0]+=count[i];
			type[2][6]+=ticketPrice[i];
			switch (ageGroup[i]){
				case 1:
					type[2][1]+=count[i];
					break;
				case 2:
					type[2][2]+=count[i];
					break;
				case 3:
					type[2][3]+=count[i];
					break;
				case 4:
					type[2][4]+=count[i];
					break;
				case 5:
					type[2][5]+=count[i];
					break;
			}
		}
		else if (ticketType[i]==2 && ticketTime[i]==2){
			type[3][0]+=count[i];
			type[3][6]+=ticketPrice[i];
			switch (ageGroup[i]){
				case 1:
					type[3][1]+=count[i];
					break;
				case 2:
					type[3][2]+=count[i];
					break;
				case 3:
					type[3][3]+=count[i];
					break;
				case 4:
					type[3][4]+=count[i];
					break;
				case 5:
					type[3][5]+=count[i];
					break;
			}
		}
	}
}

void printKindTicket() {
	printf("================== 권종 별 판매현황 ==================\n\n");
	printf("종합이용권 + 1Day 총 %d매\n", type[0][0]);
	printf("노인 %d매, 성인 %d매,청소년 %d매, 어린이 %d매, 유아 %d매\n",
						type[0][1],type[0][2],type[0][3],type[0][4],type[0][5]);
	printf("종합이용권 + 1Day 총 매출 : %d원\n\n", type[0][6]);
	
	printf("종합이용권 + After4 총 %d매\n", type[1][0]);
	printf("노인 %d매, 성인 %d매,청소년 %d매, 어린이 %d매, 유아 %d매\n",
						type[1][1],type[1][2],type[1][3],type[1][4],type[1][5]);
	printf("종합이용권 + After4 총 매출 : %d원\n\n", type[1][6]);
	
	printf("파크이용권 + 1Day 총 %d매\n", type[2][0]);
	printf("노인 %d매, 성인 %d매,청소년 %d매, 어린이 %d매, 유아 %d매\n",
						type[2][1],type[2][2],type[2][3],type[2][4],type[2][5]);
	printf("파크이용권 + 1Day 총 매출 : %d원\n\n", type[2][6]);
	
	printf("파크이용권 + After4 총 %d매\n", type[3][0]);
	printf("노인 %d매, 성인 %d매,청소년 %d매, 어린이 %d매, 유아 %d매\n",
						type[3][1],type[3][2],type[3][3],type[3][4],type[3][5]);
	printf("파크이용권 + After4 총 매출 : %d원\n\n", type[3][6]);
	printf("======================================================\n\n");
} 

void makeKindReport() {
	FILE *fp1 = fopen("report1.csv", "w");
	fprintf(fp1,"총 매수,노인,성인,청소년,어린이,유아,총 매출\n");
	for (int i=0;i<4;i++){
		fprintf(fp1,"%d,%d,%d,%d,%d,%d,%d\n",type[i][0],type[i][1],type[i][2]
								,type[i][3],type[i][4],type[i][5],type[i][6]);
	}
	fclose(fp1);
}

void dayByTicket(){
	time[k][0]=year[0],time[k][1]=month[0],time[k][2]=day[0],time[k][3]=ticketPrice[0];
	for (int i=1;i<index;i++){
		if (time[k][0]==year[i] && time[k][1]==month[i] && time[k][2]==day[i]){
			time[k][3]+=ticketPrice[i];
		}
		else {
			k++;
			time[k][0]=year[i],time[k][1]=month[i],time[k][2]=day[i],time[k][3]=ticketPrice[i];
		}
	}
}

void printDayTicket() {
	printf("==== 날짜별 매출 현황 ====\n");
	for (int i=0;i<=k;i++)
		printf("%d년 %02d월 %02d일 %d원\n",time[i][0],time[i][1],time[i][2],time[i][3]);
	printf("\n");
}

void makeDayReport() {
	FILE *fp2 = fopen("report2.csv", "w");
	fprintf(fp2,"년,월,일,총 매출\n");
	for (int i=0;i<=k;i++){
		fprintf(fp2,"%d,%d,%d,%d\n",time[i][0],time[i][1],time[i][2],time[i][3]);
	}
	fclose(fp2);
}

void discountTicket() {
	for (int i=0;i<index;i++){
		com[6]+=count[i];
		switch (discountType[i]){
			case 1:
				com[0]+=count[i];
				break;
			case 2:
				com[1]+=count[i];
				break;
			case 3:
				com[2]+=count[i];
				break;
			case 4:
				com[3]+=count[i];
				break;
			case 5:
				com[4]+=count[i];
				break;
			case 6:
				com[5]+=count[i];
				break;
		}
	}
}

void printDiscountTicket() {
	printf("===== 우대권 판매 현황 =====\n");
	printf("%-20s %4d매\n","총 판매 티켓수 :",com[0]);
	printf("%-20s %4d매\n","우대없음  :",com[1]);
	printf("%-20s %4d매\n","장애인 :",com[2]);
	printf("%-20s %4d매\n","국가유공자 :",com[3]);
	printf("%-20s %4d매\n","휴가장병 :",com[4]);
	printf("%-20s %4d매\n","임산부 :",com[5]);
	printf("%-20s %4d매\n","다둥이 행복카드 :",com[6]);
	printf("============================\n");
}

void makeDiscountReport() {
	FILE *fp3 = fopen("report3.csv", "w");
	fprintf(fp3,"우대없음,장애인,국가유공자,휴가장병,임산부,다둥이 행복카드,합계\n");
	for (int i=0;i<7;i++){
		fprintf(fp3,"%d,",com[i]);
	}
	fclose(fp3);
} 
int main()
{
	readReport();//매출내역 가져오기 
	printReport();//매출내역 출력 
	
	kindOfTicket();//권종별 매출현황 
	printKindTicket();//권종별 매출현황 출력 
	makeKindReport();//권종별 매출현황 csv파일 생성 
	
	dayByTicket();//날짜별 매출현황 
	printDayTicket();//날짜별 매출현황 출력 
	makeDayReport();//날짜별 매출현황 csv파일 생성 
	
	discountTicket();//우대권 매출현황 
	printDiscountTicket();//우대권 매출현황 출력 
	makeDiscountReport();//우대권 매출현황 csv파일 생성 
		
	return 0;
}
