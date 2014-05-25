/******************************************************************************

  Copyright (C), 2001-2011, Huawei Tech. Co., Ltd.

 ******************************************************************************
  File Name     : 
  Version       : 
  Author        : 
  Created       : 2009/10/10
  Last Modified :
  Description   : 
  Function List :
              
  History       :
  1.Date        : 2009/10/10
    Author      : 
    Modification: Created file

******************************************************************************/
#include <stdlib.h>
#include <vector>
#include <iostream>

using namespace std;


/*****************************************************************************
Description  : 两个任意长度的正数相减
Prototype    : int Decrease(const char *pMinuend, const char *pSubtrahend, char **ppResult)
Input Param  : const char *pMinuend     被减数，以\0表示字符串结束
               const char *pSubtrahend  减数，以\0表示字符串结束
Output       : char **ppResult          减法结果，必须以\0表示字符串结束
Return Value : 成功返回0   失败返回-1
*****************************************************************************/
int Decrease(const char *pMinuend, const char *pSubtrahend, char **ppResult)
{
	vector<char> n1, n2;
	int d1 = 0, d2 = 0;
	bool b1 = false, b2 = false;
	while (*pMinuend != '\0') {
		if (*pMinuend == '.') {
			d1 = 0;
			b1 = true;
		}
		else {
			n1.push_back(*pMinuend);
			if (b1)
				d1++;
		}
		pMinuend++;
	}
	while (*pSubtrahend != '\0') {
		if (*pSubtrahend == '.') {
			d2 = 0;
			b2 = true;
		}
		else {
			n2.push_back(*pSubtrahend);
			if (b2)
				d2++;
		}
		pSubtrahend++;
	}

	int d = 0;
	if (d1 > d2) {
		d = d1;
		for (int i = 0; i < d1 - d2; i++)
			n1.push_back('0');
	}
	else {
		d = d2;
		for (int i = 0; i < d2 - d1; i++)
			n2.push_back('0');
	}

	if (n1.size() > n2.size()) {
		for (int i = 0; i < n1.size() - n2.size(); i++)
			n2.insert(n2.begin(), '0');
	}
	else {
		for (int i = 0; i < n2.size() - n1.size(); i++)
			n1.insert(n1.begin(), '0');
	}

	cout << endl;
	for (int i = 0; i < n1.size(); i++)
		cout << n1[i];
	cout << endl;
	for (int i = 0; i < n2.size(); i++)
		cout << n2[i];
	cout << endl;

	vector<char> re;
	int i = 0;
	while (i < n1.size() && n1[i] == n2[i]) {
		i++;
	}
	if (i == n1.size()) {
		*ppResult = new char[2];
		**ppResult = '0';
		*(*ppResult+1) = '\0';
		return 0;
	}
	bool n1big = true;
	if (n1[i] < n2[i]) {
		n1big = false;
		char c = 0;
		for (int j = n1.size() - 1; j >= i; j--) {
			if (n2[j] < n1[j] + c) {
				re.push_back(n2[j] + 10 - n1[j] - c + '0');
				c = 1;
			}
			else {
				re.push_back(n2[j] - n1[j] - c + '0');
				c = 0;
			}
		}
	}
	else {
		int c = 0;
		for (int j = n1.size() - 1; j >= i; j--) {
			if (n1[j] < n2[j] + c) {
				re.push_back(n1[j] + 10 - n2[j] - c + '0');
				c = 1;
			}
			else {
				re.push_back(n1[j] - n2[j] - c + '0');
				c = 0;
			}
		}
	}
    
	vector<char> rer;
	bool nozero = false;
	for (int i = re.size() - 1; i >= 0; i--) {
		if (!nozero && re[i] != '0')
			nozero = true;
		if (nozero)
			rer.push_back(re[i]);
	}
	if (d > rer.size()) {
		for (int i = 0; i < d - rer.size(); i++)
			rer.insert(rer.begin(), '0');
		rer.insert(rer.begin(), '.');
		rer.insert(rer.begin(), '0');
	}
	else if (d > 0) {
		rer.insert(rer.end()-d, '.');
	}
	if (!n1big)
		rer.insert(rer.begin(), '-');
	*ppResult = new char[rer.size()+1];
	cout << endl;
	i = 0;
	for (; i < rer.size(); i++) {
		*(*ppResult + i) = rer[i];
		cout << rer[i];
	}
	cout << endl;
	*(*ppResult + i) = '\0';
	/**ppResult = new char[re.size()+2];
	int j = 0;
	if (!n1big) {
		**ppResult = '-';
		j++;
	}
	
	for (int i = re.size() - 1; i >= d; i--) {
		if (!nozero) {
			if (re[i] != '0')
				nozero = true;
		}
		if (nozero) {
			*(*ppResult + j) = re[i];
			j++;
		}
	}
	if (d > 0) {
		if ((!n1big && j == 1) || (n1big && j == 0)) {
			*(*ppResult + j) = '0';
			j++;
		}
		*(*ppResult + j) = '.';
		j++;
		for (int i = d - 1; i >= 0; i--) {
			*(*ppResult + j) = re[i];
			j++;
		}
		*(*ppResult + j) = '\0';

		cout << *ppResult << endl;
	}*/

    return 0;

}


