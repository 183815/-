#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define N 50
#define BACKSPACE 8
typedef struct student
{
    char name[N];
    int age;
    int grade;
    long num;
    struct student *next;
}st,*pst,**ppst;


void stu_Output(pst temp)//�ļ�����
{
    system("cls");
    char IF,filename[N];
    int stu_num=0;
    do
    {
        printf("�Ƿ����ѧ����Ϣ�ļ���(��/y,��/n)");
        scanf("%s",&IF);
    }while(IF!='y'&&IF!='Y'&&IF!='n'&&IF!='N');
    if(IF=='y'||IF=='Y')
    {
        printf("�������ļ���(��ʽΪ:�̷�:\\\\�ļ���\\�ļ���.txt)");
        scanf("%s",filename);
        FILE *fp;
        fp=fopen(filename,"wb+");
    fprintf(fp,"--------------------------------------------------------\n");
    fprintf(fp,"| ѧ������ | ѧ������ | ѧ��ѧ�� | ѧ������ | ѧ���ɼ� |\n");
    fprintf(fp,"--------------------------------------------------------\n");
        while(temp)
        {
        stu_num++;
        fprintf(fp,"|%10d|",stu_num);
        fprintf(fp,"%10s|",temp->name);
        fprintf(fp,"%10d|",temp->num);
        fprintf(fp,"%10d|",temp->age);
        fprintf(fp,"%10d|\n",temp->grade);
        fprintf(fp,"--------------------------------------------------------\n");
        temp=temp->next;
        }
        fclose(fp);
        printf("ѧ���ɼ������ɹ�!\n");
    }
}



void stu_print(pst temp)//��Ϣ��ӡ
{
    int stu_num=0;
    if(temp==NULL) {printf("ѧ����Ϣ����Ϊ�գ�\n");return;}
    else
    {
    printf("ѧ����Ϣ���£������Ƿ�����\n");
    printf("--------------------------------------------------------\n");
    printf("| ѧ������ | ѧ������ | ѧ��ѧ�� | ѧ������ | ѧ���ɼ� |\n");
    printf("--------------------------------------------------------\n");
        while(temp)
    {
        stu_num++;
        printf("|%10d|",stu_num);
        printf("%10s|",temp->name);
        printf("%10d|",temp->num);
        printf("%10d|",temp->age);
        printf("%10d|\n",temp->grade);
        printf("--------------------------------------------------------\n");
        temp=temp->next;
    }
    }
}


void stu_create(ppst stu_h,ppst stu_t)//��Ϣ¼��(������)
{
    int stu_num=0;
    char IF;
        do
    {
        stu_num++;
        pst stu=(pst)calloc(1,sizeof(st));
        printf("�������%d��ѧ����Ϣ\n",stu_num);
        printf("������ѧ������:");scanf("%s",stu->name);
        printf("������ѧ��ѧ��:");scanf("%ld",&stu->num);
        printf("������ѧ������:");scanf("%d",&stu->age);
        printf("������ѧ���ɼ�:");scanf("%d",&stu->grade);
        if(*stu_h==NULL) {*stu_h=stu;*stu_t=stu;}
        else
        {
           (*stu_t)->next=stu;
           *stu_t=stu;
        }
        do
        {
            printf("�����Ƿ�������һλѧ����Ϣ(��/y,��/n)");
            scanf("%s",&IF);
        }while(IF!='y'&&IF!='Y'&&IF!='n'&&IF!='N');
     system("cls");
    }while(IF=='y'||IF=='Y');
}


void stu_find(ppst stu_h,ppst stu_t)//��Ϣ����
{
    long i;
    int stu_num=0,IF;
    char Name[N]={0};
    if(*stu_h==NULL) {printf("ѧ������Ϊ��,�޷����ң�");return;}
    else
    {
    do{
    printf("0.��ѧ�Ų���\n1.����������\n");
    printf("��������Ĳ��ҷ�ʽ:");
    scanf("%d",&IF);
    system("cls");
    }while(IF!=0&&IF!=1);
    if(IF==0)
    {
    printf("��������Ҫ����ѧ����ѧ��:");
    scanf("%ld",&i);
    *stu_t=*stu_h;
    while(*stu_t)
    {
        stu_num++;
        if(i==(*stu_t)->num)
        {
        printf("��ѧ����ϢΪ:\n");
        printf("��%d��ѧ��\n",stu_num);
        printf("ѧ������:%s\n",(*stu_t)->name);
        printf("ѧ��ѧ��:%ld\n",(*stu_t)->num);
        printf("ѧ������:%d\n",(*stu_t)->age);
        printf("ѧ���ɼ�:%d\n",(*stu_t)->grade);
        return;
        }
        *stu_t=(*stu_t)->next;
    }
    if(*stu_t==NULL) printf("��ѧ�������ڣ�");
    }
    else if(IF==1)
    {
    printf("��������Ҫ����ѧ��������:");
    scanf("%s",Name);
    *stu_t=*stu_h;
    while(*stu_t)
    {
        stu_num++;
        if(strcmp(Name,(*stu_t)->name)==0)
        {
        printf("��ѧ����ϢΪ:\n");
        printf("��%d��ѧ��\n",stu_num);
        printf("ѧ������:%s\n",(*stu_t)->name);
        printf("ѧ��ѧ��:%ld\n",(*stu_t)->num);
        printf("ѧ������:%d\n",(*stu_t)->age);
        printf("ѧ���ɼ�:%d\n",(*stu_t)->grade);
        return;
        }
        *stu_t=(*stu_t)->next;
    }
    if(*stu_t==NULL) printf("��ѧ�������ڣ�");
    }
    }
}


void stu_delete(ppst stu_h,ppst stu_t)//��Ϣɾ��
{
    long i;
    int c,IF;
    do
    {
    printf("0.��ʽ��ѧ����Ϣ\n1.ɾ��ָ��ѧ����Ϣ\n");
    printf("��������Ĳ���:");
    scanf("%d",&IF);
    }while(IF!=0&&IF!=1);
    if(IF==0)
    {
      *stu_t=*stu_h;
      pst p;
      if(*stu_h==NULL) {printf("ѧ���ļ�Ϊ��!");return;}
      while(*stu_t)
      {
          p=*stu_t;
         (*stu_t)=(*stu_t)->next;
         *stu_h=*stu_t;
          free(p);
      }
      printf("ѧ����Ϣ�Ѿ���ʽ���ɹ�!");
    }
    else if(IF==1)
    {
    printf("��������Ҫɾ��ѧ����ѧ��:");
    scanf("%ld",&i);
    *stu_t=*stu_h;
    pst p=NULL;
    if(*stu_h==NULL)
    {
        printf("ѧ������Ϊ��!\n");
        return;
    }
    else
    {
      while(*stu_t)
      {
        if(i==(*stu_t)->num)
          {
              p=*stu_t;
              (*stu_t)=(*stu_t)->next;
              *stu_h=*stu_t;
              free(p);
              printf("ɾ���ɹ���\n");
              return;
          }
        else if((*stu_t)->next&&i==(*stu_t)->next->num)
        {
              p=(*stu_t)->next;
            (*stu_t)->next=p->next;
            free(p);
            printf("ɾ���ɹ�!\n");
            return;
        }
        *stu_t=(*stu_t)->next;
      }
      if(*stu_t==NULL) printf("δ�ҵ���ѧ��\n");
    }
}
}


void stu_insert(ppst stu_h,ppst stu_t)//����
{
    long i=-1;
    int c=0;
    printf("��������Ҫ���ѧ����λ��(���ֱ�������ĩβ������-1):");
    scanf("%ld",&i);
    *stu_t=*stu_h;
    pst stu=(pst)calloc(1,sizeof(st));
    printf("������ѧ������:");scanf("%s",stu->name);
    printf("������ѧ��ѧ��:");scanf("%ld",&stu->num);
    printf("������ѧ������:");scanf("%d",&stu->age);
    printf("������ѧ���ɼ�:");scanf("%d",&stu->grade);
    if(*stu_h==NULL)
    {
        *stu_h=stu;
        printf("��ӳɹ���\n");
        Sleep(1000);
        return;
    }
    else
    {
      while(*stu_t)
      {
          c++;
        if(i==1||i==0)
          {
             stu->next=*stu_h;
             *stu_h=stu;
              printf("��ӳɹ���\n");
              Sleep(1000);
              return;
          }
        else if((*stu_t)->next&&i-1==c)
        {
             stu->next=(*stu_t)->next;
             (*stu_t)->next=stu;
            printf("��ӳɹ���\n");
            Sleep(1000);
            return;
        }
        else if(i==-1&&(*stu_t)->next==NULL)
        {
            (*stu_t)->next=stu;
            *stu_t=stu;
            Sleep(1000);
            printf("��ӳɹ���\n");
            return;
        }
        *stu_t=(*stu_t)->next;
      }
      if(*stu_t==NULL) printf("���λ�ó�����\n");
    }
}


void stu_change(ppst stu_h,ppst stu_t)//��
{
    long i;
    int stu_num=0,IF;
    if(*stu_h==NULL) {printf("ѧ������Ϊ��,�޷����ң�");return;}
    else
    {printf("������ѧ�Ž��в���:");
    scanf("%ld",&i);
    *stu_t=*stu_h;
    while(*stu_t)
    {
    stu_num++;
    if((*stu_t)->num==i)
    {
    printf("��ѧ��Ϊ��%d��\n",stu_num);
    do
    {
    printf("���Ҫ���������밴0\n���Ҫ����ѧ���밴1\n���Ҫ���������밴2\n���Ҫ���ĳɼ��밴3:");
    scanf("%d",&IF);
    }while(IF!=0&&IF!=1&&IF!=2&&IF!=3);
    switch(IF)
    {
    case 0:printf("��������ĺ�ѧ��������:");scanf("%s",(*stu_t)->name);break;
    case 1:printf("��������ĺ�ѧ����ѧ��:");scanf("%ld",&(*stu_t)->num);break;
    case 2:printf("��������ĺ�ѧ��������:");scanf("%d",&(*stu_t)->age);break;
    case 3:printf("��������ĺ�ѧ���ĳɼ�:");scanf("%d",&(*stu_t)->grade);break;
    }
    return;
    }
    *stu_t=(*stu_t)->next;
    }
    if(*stu_t==NULL) printf("��ѧ�������ڣ�");
}
}


void stu_order(ppst stu_h,ppst stu_t)//����
{
    int IF;
    if(*stu_h==NULL) {printf("ѧ������Ϊ�գ�");return;}
    else
    {
    do
    {printf("0.��ѧ���ɼ�����\n1.��ѧ��ѧ������\n");
    printf("��������Ĳ���:");
    scanf("%d",&IF);
    system("cls");
    }while(IF!=0&&IF!=1);
    if(IF==0)
    {
    *stu_t=*stu_h;
    pst stu_t1=*stu_t;
    while(*stu_t)
    {
        while(stu_t1)
        {
            if(stu_t1&&(*stu_t)->grade<stu_t1->grade)
            {
                pst p=(pst)calloc(1,sizeof(st));//�����м���洢��Ϣ
                strcpy(p->name,(*stu_t)->name);
                p->num=(*stu_t)->num;
                p->age=(*stu_t)->age;
                p->grade=(*stu_t)->grade;
                strcpy((*stu_t)->name,stu_t1->name);
                (*stu_t)->num=stu_t1->num;
                (*stu_t)->age=stu_t1->age;
                (*stu_t)->grade=stu_t1->grade;
                strcpy(stu_t1->name,p->name);
                stu_t1->num=p->num;
                stu_t1->age=p->age;
                stu_t1->grade=p->grade;
                free(p);
            }
        stu_t1=stu_t1->next;
        }
      *stu_t=(*stu_t)->next;
      stu_t1=*stu_t;
    }
    printf("�ɼ����гɹ�!\n");
    }
    else if(IF==1)
    {
    *stu_t=*stu_h;
    pst stu_t1=*stu_t;
    while(*stu_t)
    {
        while(stu_t1)
        {
            if(stu_t1&&(*stu_t)->num>stu_t1->num)
            {
                pst p=(pst)calloc(1,sizeof(st));//�����м���洢��Ϣ
                strcpy(p->name,(*stu_t)->name);
                p->num=(*stu_t)->num;
                p->age=(*stu_t)->age;
                p->grade=(*stu_t)->grade;
                strcpy((*stu_t)->name,stu_t1->name);
                (*stu_t)->num=stu_t1->num;
                (*stu_t)->age=stu_t1->age;
                (*stu_t)->grade=stu_t1->grade;
                strcpy(stu_t1->name,p->name);
                stu_t1->num=p->num;
                stu_t1->age=p->age;
                stu_t1->grade=p->grade;
                free(p);
            }
        stu_t1=stu_t1->next;
        }
      *stu_t=(*stu_t)->next;
      stu_t1=*stu_t;
    }printf("��ѧ�����гɹ�!\n");
    }
}
}



char stu_Iutput()//�ļ���ȡ
{
char IF,filename[N],buf[N];
    do
    {
        printf("�Ƿ��ȡѧ����Ϣ�ļ���(��/y,��/n)");
        scanf("%s",&IF);
    }while(IF!='y'&&IF!='Y'&&IF!='n'&&IF!='N');
    if(IF=='y'||IF=='Y')
    {
        printf("�������ȡ�ļ�λ��(��ʽΪ:�̷�:\\\\�ļ���\\�ļ���.txt)");
        scanf("%s",filename);
        system("cls");
        FILE *fp;
        if((fp=fopen(filename,"rb"))!=NULL)
        {
        rewind(fp);
        while(!feof(fp))
        {
        fgets(buf,sizeof(buf),fp);
        printf("%s",buf);
        memset(buf,0,sizeof(buf));
        }
        fclose(fp);
        printf("\nѧ����Ϣ��ȡ���!\n");
        return filename;
        }
        else if(fp=fopen(filename,"rb")==NULL) {printf("�ļ�������!\n");return;}
}
}



   void stu_read(ppst stu_h,ppst stu_t)
{
    char IF,temp[N]={0},ch;
    int d;
    int i=0,j=0,n=0;
    *stu_t=*stu_h;
    pst stu=NULL;
    do
    {
        printf("�Ƿ��ϴδ浵ѧ����Ϣ�ļ��������ݿ⣿(��/y,��/n)");
        scanf("%s",&IF);
    }while(IF!='y'&&IF!='Y'&&IF!='n'&&IF!='N');
    if(IF=='y'||IF=='Y')
    {
        FILE *fp;
        if((fp=fopen("�浵(��ɾ)","rb+"))!=NULL)
        {
        while((ch=fgetc(fp))!=EOF)
        {
            if(ch=='*'){
            stu=(pst)calloc(1,sizeof(st));}
            else if(ch!='|'&&ch!=' '&&ch!='\n'&&ch>='A'&&ch<='z')
            {
               temp[n++]=ch;
            }
            else if(ch!='|'&&ch!=' '&&ch!='\n'&&ch>='0'&&ch<='9')
            {
                temp[n++]=ch;
            }
            else if(ch==' ')
            { j++;n=0;
              switch(j)
              {
                 case 1:strcpy(stu->name,temp);memset(temp,0,sizeof(temp));break;
                 case 2:stu->num=atol(temp);memset(temp,0,sizeof(temp));break;
                 case 3:stu->age=atoi(temp);memset(temp,0,sizeof(temp));break;
                 case 4:stu->grade=atoi(temp);memset(temp,0,sizeof(temp));break;
              }
            }
            else if(ch=='|')
            {
                if(*stu_h==NULL) {*stu_h=stu;*stu_t=stu;} else {(*stu_t)->next=stu;*stu_t=stu;}
              j=0;}
            }
            fclose(fp);
            }
        else if((fp=fopen("Data","rb+"))==NULL) {printf("�޴浵ѧ���ļ�!���½��浵!\n");return;}}
        else if(IF=='n'||IF=='N') return;
}



void stu_save(pst temp)
{
    system("cls");
    char If;
    do{
    printf("�Ƿ����Ϣ���д浵�����´�ֱ�ӽ��ж�ȡ?��/y ��/n\n");
    scanf("%s",&If);
    }while(If!='y'&&If!='n'&&If!='Y'&&If!='N');
    if(If=='y'||If=='Y')
    {
    FILE *fp;
    fp=fopen("�浵(��ɾ)","wb+");
    while(temp)
        {
        fprintf(fp,"*%s ",temp->name);
        fprintf(fp,"%d ",temp->num);
        fprintf(fp,"%d ",temp->age);
        fprintf(fp,"%d |\n",temp->grade);
        temp=temp->next;
        }
        fclose(fp);
        printf("�浵�ɹ�!\n");
    }
    else return;
}



void adm_set(char password[N])
{
    char ch,temp[N]={0},temp1[N]={0};
    int i=0;
    system("cls");
    printf("���������ù���Ա����:");
        while((ch = getch()) != '\r'&&i< N)
    {
    if (ch == BACKSPACE)
    {
    if (i > 0)
    {
    temp[--i] = NULL;
    printf("\b ");
    printf("%c%c%c", BACKSPACE, ' ', BACKSPACE);
    }
    }
    else
    {
    temp[i++] = ch;
    printf("*");
    }
    }
    system("cls");
    printf("������һ�ι���Ա����:");
        i=0;
        while((ch = getch()) != '\r'&&i< N)
    {
    if (ch == BACKSPACE)
    {
    if (i > 0)
    {
    temp1[--i] = NULL;
    printf("\b ");
    printf("%c%c%c", BACKSPACE, ' ', BACKSPACE);
    }
    }
    else
    {
    temp1[i++] = ch;
    printf("*");
    }
    }
    if(strcmp(temp1,temp)==0){memset(password,0,sizeof(password));strcpy(password,temp);printf("\n�������óɹ�!");Sleep(500);}
    else {printf("\n���������������\n");Sleep(1000);}
}



void adm_change(char password[N])
{
    char ch,word[N]={0};
    int i=0;
    system("cls");
    printf("���������Ա�������ݽ�����֤:");
    while((ch = getch()) != '\r'&&i< N)
    {
    if (ch == BACKSPACE)
    {
    if (i > 0)
    {
    word[--i] = NULL;
    printf("\b ");
    printf("%c%c%c", BACKSPACE, ' ', BACKSPACE);
    }
    }
    else
    {
    word[i++] = ch;
    printf("*");
    }
    }
    if(strcmp(word,password)==0)
    {
    memset(password,0,sizeof(password));
    adm_set(password);
    }
    else {printf("\n�������!\n");Sleep(1000);}
}




void stu_destroy(ppst stu_h)
{
    while(*stu_h)
    {
    pst p=*stu_h;
    *stu_h=(*stu_h)->next;
    free(p);
    }
}




  main()
{
    int IF,i;
    char filename[N],password[N]={"0000"},word[N],If;
    do{
    printf("����Ա���жԵ����޸ĺ�ɾ��Ȩ��  ����ԱĬ������Ϊ:0000  \n");
    getchar();
    printf("�Ƿ����ù���Ա���룿(��/y ��/n)\n");
    scanf("%s",&If);
    }while(If!='y'&&If!='n'&&If!='Y'&&If!='N');
    if(If=='y'||If=='Y') {adm_set(password);}
    for(;;)
    {
    pst stu_h=NULL,stu_t=NULL;
    system("cls");
    do{
    printf("��ӭ��¼ѧ������ϵͳ��\n");
    printf("---------------\n");
    printf("0.�½�ѧ������ |\n1.����ѧ������ |\n---------------\n���������Ĳ���:");
    scanf("%d",&IF);
    system("cls");
    }while(IF!=0&&IF!=1);
    if(IF==0)  {stu_create(&stu_h,&stu_t);}
    else if(IF==1) {stu_read(&stu_h,&stu_t);}
modify:
    system("cls");
    {
    do
    {
    stu_print(stu_h);
    printf("---------------\n");
    printf("|0.�½�ѧ����Ϣ|\n|1.���ѧ����Ϣ|\n|2.ɾ��ѧ����Ϣ|\n|3.�޸�ѧ����Ϣ|\n|4.����ѧ����Ϣ|\n|5.ѧ����Ϣ����|\n|6.����ѧ����Ϣ|\n|7.�޸Ĺ�������|\n|8.�˳�����    |\n");
    printf("---------------\n");
    printf("���������Ĳ���:");
    scanf("%d",&IF);
    system("cls");
    }while(IF!=0&&IF!=1&&IF!=2&&IF!=3&&IF!=4&&IF!=5&&IF!=6&&IF!=7&&IF!=8);
    switch(IF)
    {
    case 0:stu_create(&stu_h,&stu_t);system("pause");break;
    case 1:stu_insert(&stu_h,&stu_t);system("pause");break;//��
    case 2:{printf("���������Ա����:");scanf("%s",word);if(strcmp(password,word)==0){stu_delete(&stu_h,&stu_t);}else {printf("�������!");}system("pause");break;}//ɾ
    case 3:{printf("���������Ա����:");scanf("%s",word);if(strcmp(password,word)==0){stu_change(&stu_h,&stu_t);}else {printf("�������!");}system("pause");break;}//��
    case 4:stu_find(&stu_h,&stu_t);system("pause");break;//��
    case 5:stu_order(&stu_h,&stu_t);system("pause");break;//��
    case 6:stu_Output(stu_h);system("pause");break;//�����ɼ��ļ�
    case 7:adm_change(password);break;//�޸Ĺ���Ա����
    case 8:goto End;break;
    }
    system("cls");
    stu_print(stu_h);
    do{
    printf("�Ƿ������ѧ����Ϣ���в�����(��/y ��/n)");
    scanf("%s",&If);
    }while(If!='y'&&If!='n'&&If!='Y'&&If!='N');
    if(If=='y'||If=='Y') {goto modify;}
    }
    End:
    {
    stu_save(stu_h);
    stu_Output(stu_h);
    stu_destroy(&stu_h);
    printf("��ӭ�´�ʹ��ѧ������ϵͳ!\n");
    printf("\n\n                                                                      Made by ˧����\n");
    }
    system("pause");
    }
}
