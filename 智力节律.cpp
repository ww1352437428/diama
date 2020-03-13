#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
struct date
{
	int year;
	int month;
	int day;
};
int main(void)
{
	int isPrime(int year);
	int dateDiff(struct date mindate, struct date maxdate);
	struct date mindate, maxdate;
	int days;
	int i;
	printf("请输入你的出生年月日，中间用-隔开:");
	scanf("%d-%d-%d", &mindate.year, &mindate.month, &mindate.day);
	printf("请输入你此时的年月日，中间用-隔开:");
	scanf("%d-%d-%d", &maxdate.year, &maxdate.month, &maxdate.day);
    days = dateDiff(mindate, maxdate);
	i = days % 33;
	if(i<=1)
{printf("%1.0周期日\n");
printf("%这天，你处在智力节律的周期日。刚经历过低潮期的你，智力正在逐渐恢复，反应力和判断力会逐渐变快哦，很快你就能变成聪明的小机灵鬼了呢!但此时你的辨别能力会比较差，所以请三思而后行。\n");}
else if(i<18)
{printf("%高潮日\n");
printf("%这天，你处在智力节律的高潮日。思维敏捷，反应快，记东西快，逻辑性强，解决复杂问题能力强，智力开阔，判断决策能力强。但，要注意的是，不久后，你就要进入临界日，容易判断失误，所以做决定要谨慎。\n");}
else if(i<19)
{printf("%临界日\n");
printf("%这天，你处在智力节律的临界日。头脑不大灵光，变得麻木，效率不高，容易判断失误，做事“无厘头”，易出差错。由于您要进入智力节律的低潮期，所以思维会变得迟钝。这种情况大概持续一个星期才会好转，所以，不要因为做事上出错而自责，这是自然规律。\n");}
else
{printf("%低潮期\n");
printf("%这天，你处在智力节律的低潮期。智力会受到抑制，反应变得迟钝，健忘，注意力不集中，判断力降低，记忆力变差，从而工作效率变低。但这只是暂时的现象，会在两个星期以内恢复的。这段时间您要保持心态平稳，\n");}

	return 0;
}

/************************************************************************/
/*    判断闰年函数(4年一润,100年不润,400年再润)                         */
/************************************************************************/
int isPrime(int year)
{
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
	{
		return 1;
	}
	else
	{
		return 0;
	}

}

int dateDiff(struct date mindate, struct date maxdate)
{
	int days = 0, flag = 1;
	const int primeMonth[12] = { 31,29,31,30,31,30,31,31,30,31,30,31 };
	const int notPrimeMonth[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

	/************************************************************************/
	/*        交换两个日期函数,将小的日期给mindate,将大的日期给maxdate     */
	/************************************************************************/
	struct date tmp;
	if ((mindate.year > maxdate.year) || (mindate.year == maxdate.year && mindate.month > maxdate.month) || (mindate.year == maxdate.year && mindate.month == maxdate.month && mindate.day > maxdate.day))
	{
		tmp = mindate;
		mindate = maxdate;
		maxdate = tmp;
	}

	int maxmonth, minmonth;
	/************************************************************************/
	/* 主要思路:拿2002-8-8   2005-2-22来说                                  */
	/*   将2004-8-8---2005-2-22----2005-7-8                                 */
	/*一前一后刚好N年,算出2005-2-22到2005-7-8的天数,然后用总年*36(5|6)减掉) */
	/*          2002-9-8      2005-11-22                                    */
	/*          2002-9-8-----2005-9-8-----2005-11-22(这次是加上后面天数)    */
	/*如何判断是加还是减呢?年大而月小的,则是减,程序中用flag标示             */
	/************************************************************************/
	if (maxdate.month < mindate.month)
	{
		maxmonth = mindate.month;
		minmonth = maxdate.month;
		flag = -1;
	}
	else
	{
		maxmonth = maxdate.month;
		minmonth = mindate.month;
		flag = 1;
	}

	/************************************************************************/
	/*  从mindate.year开始累加到maxdate.year                                */
	/************************************************************************/
	for (int j = mindate.year; j < maxdate.year; ++j)
	{
		if (isPrime(j) == 1)
		{
			days += 366;
		}
		else
			days += 365;
	}

	/************************************************************************/
	/* 从minmonth累加到maxmonth,分闰年和平年                                */
	/************************************************************************/
	int day;
	if (isPrime(maxdate.year) == 1)
	{

		for (int i = minmonth; i < maxmonth; i++)
		{
			day = primeMonth[i - 1] * flag;
			days = days + day;
		}
		days = days + maxdate.day - mindate.day;
	}
	else
	{
		for (int i = minmonth; i < maxmonth; i++)
		{
			day = notPrimeMonth[i - 1] * flag;
			days = days + day;
		}
		days = days + maxdate.day - mindate.day;
	}
	return days;
}