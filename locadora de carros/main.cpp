
#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Invoice.h"


int main()
{

	CInvoice Order;

	Order.ProcessOrder();
	Order.ShowOrder();

    return 0;
}
