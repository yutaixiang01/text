#pragma once
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

//�����ַ����飬�� ��ţ��������е���Ʒ
//���ս�ɫ���������Ǽ����з��飬������Դ�ڳ�פ��˵��

//��פ13����������
extern const char weapon_3star[][200];
//��פ16���ǽ�ɫ
extern const char char_4star[][200];
//18����������
extern const char weapon_4star[][200];
//��פ10 ��������
extern const char weapon_char_5star[][200];
//���������
extern int jiuchan_num;
//�������Ʒ�Ǽ�
extern int xingji;
//��������
extern int r;
//����ssr-1��û��������Ʒ
extern int ssr;
//����sr-1��û��������Ʒ
extern int sr;
//����һ���ַ�����洢���
extern char results[100];
//��Ȩ��Ϊ10000
extern int Wceil;
//������ƷȨ��
extern int wr;
//дһ��ѡ����ӵ��жϺ���
extern void xuanzechizi();
//���غ���
extern void chanzgzhuchouka();
//ȷ���Ǽ�֮����������
extern void queding_xingji();
//��ӡ����������
extern char* result(int xingji);
//����һ�����ȷֲ���[1,max]�ϵ������
extern int RF1(int max);
//ȡ������֮�����Сֵ
extern int min(int a, int b);
//���ǽ�ɫȨ��  ����ssr���ӣ�������û�г��е�������ࣩȨ�ر��   
//ssrΪ0��Ȩ��Ϊ 60   ssr���ڵ���74֮��Ȩֵÿ������600  Ȩֵ���ʱ����10000
extern int wssr(int ssr);
//���ǽ�ɫ������Ȩ��
//srΪ0ʱȨ��Ϊ510    sr���ڵ���8֮��Ȩ��ÿ������5100   Ȩ������Ǵ���10000
extern int wsr(int sr);
//����һ������
extern int baodi;
//�������
extern int chizi;