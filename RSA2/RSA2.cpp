// RSA2.cpp: ������� ���� �������.
#include <iostream>
#include <clocale>
#include <conio.h>
#include <Windows.h>
#include <ctime>
#include "BigIntegerLibrary.hh"
using namespace std;

BigUnsigned k=15, N=5, P, Q, Nr, Ka, Kb, *blockNums, *blockChif, buf=0, Fi;
int nBlocks;
string input, output;
const BigUnsigned simple[303]={2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499, 503, 509, 521, 523, 541, 547, 557, 563, 569, 571, 577, 587, 593, 599, 601, 607, 613, 617, 619, 631, 641, 643, 647, 653, 659, 661, 673, 677, 683, 691, 701, 709, 719, 727, 733, 739, 743, 751, 757, 761, 769, 773, 787, 797, 809, 811, 821, 823, 827, 829, 839, 853, 857, 859, 863, 877, 881, 883, 887, 907, 911, 919, 929, 937, 941, 947, 953, 967, 971, 977, 983, 991, 997, 1009, 1013, 1019, 1021, 1031, 1033, 1039, 1049, 1051, 1061, 1063, 1069, 1087, 1091, 1093, 1097, 1103, 1109, 1117, 1123, 1129, 1151, 1153, 1163, 1171, 1181, 1187, 1193, 1201, 1213, 1217, 1223, 1229, 1231, 1237, 1249, 1259, 1277, 1279, 1283, 1289, 1291, 1297, 1301, 1303, 1307, 1319, 1321, 1327, 1361, 1367, 1373, 1381, 1399, 1409, 1423, 1427, 1429, 1433, 1439, 1447, 1451, 1453, 1459, 1471, 1481, 1483, 1487, 1489, 1493, 1499, 1511, 1523, 1531, 1543, 1549, 1553, 1559, 1567, 1571, 1579, 1583, 1597, 1601, 1607, 1609, 1613, 1619, 1621, 1627, 1637, 1657, 1663, 1667, 1669, 1693, 1697, 1699, 1709, 1721, 1723, 1733, 1741, 1747, 1753, 1759, 1777, 1783, 1787, 1789, 1801, 1811, 1823, 1831, 1847, 1861, 1867, 1871, 1873, 1877, 1879, 1889, 1901, 1907, 1913, 1931, 1933, 1949, 1951, 1973, 1979, 1987, 1993, 1997, 1999};

BigUnsigned pow(BigUnsigned a, BigUnsigned b) //���������� � �������
{
	BigUnsigned h=a;
	for(BigUnsigned i=0; i<b-1; i++)
		a*=h;
	return a;
}

BigUnsigned randA(BigUnsigned k) // ��������� �������� k-������� �����
{
	if(k<=0) return 1; // ���� ������� ����������� k �������
	BigUnsigned r = 0; // ����� ��� ���������
	bool flag=0; // ������ ������� ����
	BigUnsigned a; // ����� ��� �����������
	while(k!=0) // ������ ���� ���� �� ����������
	{
		if(k<=15&&flag) {r=r*pow(2, k);} // �������� �� k ��� ����� ������� �� ������� ����
		if(k<=15) {a=pow(2, k); k=0; if(flag==0) flag=1;} // ��������� ����������� �� 2^k, �������� k
		if(k>15&&flag) {r=r*(BigUnsigned)32768;} // �������� �� 2^15 ��� ����� ������� �� ������� ����
		if(k>15) {a=32768; k-=15; if(flag==0) flag=1;} // ��������� ���������� ���� �� 15
		r+=BigUnsigned(rand())%a; // ��������� �������������� ����� ����� rand()
	}
	return r;
}

bool rabinaMilleraTest(BigUnsigned p) // ���� ������-�������
{
	BigUnsigned b=0, m, temp=p-1;
	while(temp%2==0) // ������� b
	{
		temp=temp/2;
		b++;
	}
	m=(p-1)/modexp(2, b, p); // ������� m
	for(BigUnsigned i=0; i<N; i++) // N ��������
	{
		BigInteger a=randA(k-10);
		while(a>p) a=randA(k-10); // ������������ ���� �� ������� a<p
		
		BigInteger j=0;
		BigInteger z=modexp(a, m, p);
		if(z==1||z==p-1) continue; // ��������, ���������� ���������
		x:
		if(j>0&&z==1) return false; // �� ��������, �������
		j++;
		if(j<b&&z!=p-1) {z=(z*z)%p; goto x;}
		else if(z==p-1) continue; // ��������, ���������� ���������
		else if(j==b&&z!=p-1) return false; // �� ��������, �������
	}
	return true; // ����� �������, �������
}

BigUnsigned generateSimpleNum(BigUnsigned n) // ��������� �������� �����
{
	bool flag;
	BigUnsigned p;
	while(true)
	{
		p=randA(n); // ��������� ����� ��� ��������
		if(p<pow(2, k)/2) continue;
		p=p|0x1; // ������ ����� ��������
		flag=true; // ���� �����
		for(int i=0; i<303; i++) // �������� �� ������� �� ������� ����� �� 1999
			if(p%simple[i]==0) {flag=false; break;}
		if(!flag) continue; // ����� �� ������ ��������
		if(rabinaMilleraTest(p)) break; // ���� ������ �������� �-� �������
		else continue; // ����� �������� ����� ��������
	}
	return p; // ������� �������� �����
}

void rsaEncrypt()
{
	string tempStr;
	P=generateSimpleNum(15); // ��������� P
	Q=generateSimpleNum(15); // ��������� Q
	Nr=P*Q;

	Fi=(P-1)*(Q-1);
	BigInteger a, b, d, x, y;
	while(true) // �������� ������ Ka, Kb
	{
		do	Ka=generateSimpleNum(30); while(Ka>Fi);
		a=Ka; b=Fi;
		extendedEuclidean(a, b, d, x, y); // ���������� �������� �������
		if(x>0) {Kb=stringToBigUnsigned(bigIntegerToString(x)); break;}
	}
	blockNums=new BigUnsigned[input.size()];
	blockChif=new BigUnsigned[input.size()];
	int indIn=0, indNum=0;
	while(indIn<input.size()) // �������� �� �����
	{
		buf+=(int)input[indIn++];
		if(indIn>=input.size()) {blockNums[indNum++]=buf; break;}
		while(true)
		{
			buf*=256;
			buf+=(int)input[indIn++];
			if(indIn>=input.size()) {blockNums[indNum++]=buf; break;}
			if(buf>=Nr) {buf/=256; blockNums[indNum++]=buf; indIn--; break;}
		}
		buf=0;
	}
	nBlocks=indNum; // ������ ���������� ������
	for(int i=0; i<nBlocks; i++) // ����������
		blockChif[i]=modexp(blockNums[i], Ka, Nr);
}

void rsaDecrypt()
{
	string tempStr;
	BigUnsigned *temp=new BigUnsigned[nBlocks];
	for(int i=0; i<nBlocks; i++) // �������������
	{
		blockNums[i]=modexp(blockChif[i], Kb, Nr);
		temp[i]=blockNums[i];
	}
	int indIn=0, indNum=nBlocks-1;
	while(indIn<input.size()) // ��������� ������ �� �������
	{
		if(temp[indNum]<1) indNum--;
		if(indNum<0) break;
		tempStr+=(char)(temp[indNum]%256).toInt();
		temp[indNum]/=256;
	}
	for(int i=tempStr.size()-1; i>=0; i--) // ������������ ������ ����������
		output+=tempStr[i];
}

#include "Form1.h"

using namespace RSA2;

[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
	//srand(time(0));
	// ��������� ���������� �������� Windows XP �� �������� �����-���� ��������� ����������
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false); 

	// �������� �������� ���� � ��� ������
	Application::Run(gcnew Form1());
	return 0;
}
