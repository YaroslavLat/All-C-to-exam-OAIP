#include<stdio.h>
//#include<string>
#include<math.h>
#include<stdbool.h>




//Calculating funtions
int Reorder_point_Calculate(int daily_demand, int lead_days, int safety_days)
{
	int reorder_point;
	reorder_point = daily_demand * (lead_days + safety_days);
	return reorder_point;
}

int Expected_during_lead_Calculate(int daily_demand, int lead_days)
{
	int expected_during_lead = daily_demand * lead_days;
	return expected_during_lead;
}

int Target_stock_Calculate(int reorder_point, int daily_demand, int safety_days)
{
	int target_stock;
	target_stock = reorder_point + daily_demand * safety_days;
	return target_stock;
}

double Days_left_Calculate(int stock, int daily_demand)
{
	double days_left;
	days_left = stock / daily_demand;
	return days_left;
}

//tak kak obichni min ne workaet nixya
#define MAX_TARGET(a, b) ((a) > (b) ? (a) : (b))
#define MIN_TARGET(a, b) ((a) < (b) ? (a) : (b))
int Recommended_order_Calculate(int max_order, int target_stock,int stock)
{
	int recommended_order = 0;
	//recommended_order = min(max_order, max(0, target_stock - stock));
	recommended_order = MIN_TARGET(max_order, MAX_TARGET(0, (target_stock - stock)));
	int temp_max = 0;
	
	

	return recommended_order;
}


//Vvod znachenie
int Enter_Stock()
{
	bool isAllCorrect = false;
	int stock;
	do
	{
		printf("Ente stock. Edidnica izmereniya - shtyki\n");
		if (scanf_s("%d", &stock) != 1)
		{
			printf("Error! You cam enter zelie chisla\n");
			while (getchar() != '\n');
			continue;
		}

		if (stock <= 0)
		{
			printf("Error! Stock cant be minus\n");
		}
		else
		{
			printf("Stok is corect! Stock = %d\n", stock);
			isAllCorrect = true;
		}


	} while (isAllCorrect != true);
	return stock;
}


int Enter_Daily_Demand()
{
	bool isAllCorrect = false;
	int daily_Demand;
	do
	{
		printf("Ente daily demand. Edidnica izmereniya - shtyki\n");
		if (scanf_s("%d", &daily_Demand) != 1)
		{
			printf("Error! You cam enter zelie chisla\n");
			while (getchar() != '\n');
			continue;
		}

		if (daily_Demand <= 0)
		{
			printf("Error! daily_Demand cant be minus\n");
		}
		else
		{
			printf("daily_Demand is corect! Stock = %d\n", daily_Demand);
			isAllCorrect = true;
		}


	} while (isAllCorrect != true);
	return daily_Demand;
}


int Enter_lead_days()
{
	bool isAllCorrect = false;
	int  lead_days;
	do
	{
		printf("Enter  lead_days. Edidnica izmereniya - shtyki\n");
		if (scanf_s("%d", &lead_days) != 1)
		{
			printf("Error! You cam enter zelie chisla\n");
			while (getchar() != '\n');
			continue;
		}

		if (lead_days <= 0)
		{
			printf("Error!  lead_days cant be minus\n");
		}
		else
		{
			printf(" lead_days is corect! Stock = %d\n", lead_days);
			isAllCorrect = true;
		}


	} while (isAllCorrect != true);
	return  lead_days;
}



int Enter_Safety_days()
{
	bool isAllCorrect = false;
	int safety_days;
	do
	{
		printf("Enter safety_days. Edidnica izmereniya - shtyki\n");
		if (scanf_s("%d", &safety_days) != 1)
		{
			printf("Error! You cam enter zelie chisla\n");
			while (getchar() != '\n');
			continue;
		}

		if (safety_days <= 0)
		{
			printf("Error! safety_days cant be minus\n");
		}
		else
		{
			printf("safety_days is corect! safety_days = %d\n", safety_days);
			isAllCorrect = true;
		}


	} while (isAllCorrect != true);
	return safety_days;
}


int Enter_Max_order()
{
	bool isAllCorrect = false;
	int max_order;
	do
	{
		printf("Enter max_order. Edidnica izmereniya - shtyki\n");
		if (scanf_s("%d", &max_order) != 1)
		{
			printf("Error! You cam enter zelie chisla\n");
			while (getchar() != '\n');
			continue;
		}

		if (max_order <= 0)
		{
			printf("Error! max_order cant be minus\n");
		}
		else
		{
			printf("max_order is corect! safety_days = %d\n", max_order);
			isAllCorrect = true;
		}


	} while (isAllCorrect != true);
	return max_order;
}


double Enter_reliability()
{
	bool isAllCorrect = false;
	double reliability;
	do
	{
		printf("Enter max_order. Edidnica izmereniya - shtyki\n");
		if (scanf_s("%lf", &reliability) != 1.0f)
		{
			printf("Error! You cam enter zelie chisla\n");
			while (getchar() != '\n');
			continue;
		}

		if (reliability <= 0)
		{
			printf("Error! reliability cant be minus\n");
		}
		else
		{
			printf("reliability is corect! reliability = %lf\n", reliability);
			isAllCorrect = true;
		}


	} while (isAllCorrect != true);
	return reliability;
}




// 8 - 9 lvl
bool report_test(bool ok)
{
	if (ok)
	{
		printf("PASS\n");
	}
	else
	{
		printf("FAIL\n");
	}
	return ok;
}

int function_tests()
{
	int failed = 0;

	printf("------- Function tests -------\n");

	printf("TEST: Reorder_point_Calculate(5, 3, 2) == 25: ");
	failed += !report_test(Reorder_point_Calculate(5, 3, 2) == 25);

	printf("TEST: Expected_during_lead_Calculate(5, 3) == 15: ");
	failed += !report_test(Expected_during_lead_Calculate(5, 3) == 15);

	printf("TEST: Target_stock_Calculate(25, 5, 2) == 35: ");
	failed += !report_test(Target_stock_Calculate(25, 5, 2) == 35);

	printf("TEST: Days_left_Calculate(20, 5) == 4: ");
	failed += !report_test(Days_left_Calculate(20, 5) == 4);

	printf("TEST: Recommended_order_Calculate(50, 35, 10) == 25: ");
	failed += !report_test(Recommended_order_Calculate(50, 35, 10) == 25);

	
	printf("TEST: Recommended_order_Calculate(20, 35, 5) == 20: ");
	failed += !report_test(Recommended_order_Calculate(20, 35, 5) == 20);

	
	printf("TEST: Recommended_order_Calculate(50, 35, 40) == 0: ");
	failed += !report_test(Recommended_order_Calculate(50, 35, 40) == 0);

	return failed;
}


int property_tests()
{
	int failed = 0;

	printf("------- Property tests -------\n");

	int daily_demand = 5;
	int lead_days = 3;
	int safety_days = 2;
	int max_order = 50;
	int stock = 10;

	int expected_lead = Expected_during_lead_Calculate(daily_demand, lead_days);
	int reorder_pt = Reorder_point_Calculate(daily_demand, lead_days, safety_days);
	int target_st = Target_stock_Calculate(reorder_pt, daily_demand, safety_days);
	int rec_order = Recommended_order_Calculate(max_order, target_st, stock);

	
	printf("PROP: reorder_point >= expected_during_lead: ");
	failed += !report_test(reorder_pt >= expected_lead);

	
	printf("PROP: target_stock >= reorder_point: ");
	failed += !report_test(target_st >= reorder_pt);

	
	printf("PROP: 0 <= recommended_order <= max_order: ");
	failed += !report_test(rec_order >= 0 && rec_order <= max_order);

	return failed;
}





int main()
{
	int stock = Enter_Stock();
	int daily_demand = Enter_Daily_Demand();
	int lead_days = Enter_lead_days();
	int safety_days = Enter_Safety_days();
	int max_order = Enter_Max_order();
	double reliability = Enter_reliability();

	if (stock < Expected_during_lead_Calculate(daily_demand, lead_days) || reliability < 70)
	{
		printf("CRITICAL\n");
	}
	else if (stock <= Reorder_point_Calculate(daily_demand, lead_days, safety_days))
	{
		printf("ORDER_NOW\n");
	}
	else if (reliability < 85)
	{

		printf(" SUPPLIER_WARNING\n");
	}
	else
	{

		printf("ENOUGH\n");
	}

	int reorder_point = Reorder_point_Calculate(daily_demand, lead_days, safety_days);
	int expected_during_lead = Expected_during_lead_Calculate(daily_demand, lead_days);
	int target_stock = Target_stock_Calculate(reorder_point, daily_demand, safety_days);
	int recommended_order = Recommended_order_Calculate(max_order, target_stock, stock);
	int days_left = Days_left_Calculate(stock, daily_demand);

	printf("\n--- Results ---\n");
	printf("reorder_point = %d\n", reorder_point);
	printf("expected_during_lead = %d\n", expected_during_lead);
	printf("target_stock = %d\n", target_stock);
	printf("recommended_order = %d\n", recommended_order);
	printf("days_left = %d\n", days_left);


	int counFails = function_tests();
	printf("Count fails: %d \n", counFails);


	int counFails_skald = property_tests();
	printf("Count fails: %d \n", counFails);

	return 0;
}