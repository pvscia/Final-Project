#include <stdio.h>
#include <string.h>

struct database{
  char name[100];
  short int age;
  char identificationNumber[15];
  char position[50];
  char employeeRank;
  int worktime_per_week=0;
  long long int nik;
  char nationality[30];
  char homeAdress[200];
  float salary;
  int holiday;
};

void print(database arr){
  printf("\nNama: %s.\n", arr.name);
  printf("Umur: %hd Tahun.\n", arr.age);
  printf("Nomor Identifikasi: %s.\n", arr.identificationNumber);
  printf("Jabatan: %s.\n", arr.position);
  printf("Rating: %c.\n", arr.employeeRank);
  printf("Jam Kerja: %d Jam/Minggu.\n", arr.worktime_per_week);
  printf("NIK: %lld.\n", arr.nik);
  printf("Kewarganegaraan: %s.\n", arr.nationality);
  printf("Alamat: %s.\n", arr.homeAdress);
  printf("Gaji: %.2f.\n", arr.salary);
  printf("Sisa Cuti: %d hari.\n\n\n", arr.holiday);
}

void replaceData(){
  char name[100];
  database replace[500];
  int counter=0,salah=0;
  printf("Masukkan Nama Pegawai\n");
  scanf("%[^\n]", name); getchar();
  FILE *freplace= fopen("DataBaseEmployee.txt", "r");
  for (int i=0;!feof(freplace);i++){
    fscanf(freplace, "%[^#]#%hd#%[^#]#%[^#]#%c#%d#%lld#%[^#]#%[^#]#%f#%d\n",
    replace[i].name,
    &replace[i].age,
    replace[i].identificationNumber,
    replace[i].position,
    &replace[i].employeeRank,
    &replace[i].worktime_per_week,
    &replace[i].nik,
    replace[i].nationality,
    replace[i].homeAdress,
    &replace[i].salary,
    &replace[i].holiday); counter++;

    if(strcmp(name,replace[i].name)!=0){
      salah++;
    }

    if(strcmp(name,replace[i].name)==0){
      salah=0;
      print(replace[i]);

      int choice;
      printf("Pilih Data Yang Ingin Dirubah: \n");
      printf("1.Nama\n2.Umur\n3.Nomor Identifikasi\n4.Jabatan\n5.Rating\n");
      printf("6.Jam Kerja\n7.NIK\n8.Kewarganegaraan\n9.Alamat\n10.Gaji\n11.Sisa Cuti\n" );
      scanf("%d",&choice); getchar();

      switch(choice){
        case 1: {
            printf("Masukkan Nama yang Baru: \n");
            char search[100];
            scanf("%[^\n]", search);getchar();
            strcpy(replace[i].name,search);
            print(replace[i]);
            printf("Data Berhasil Di rubah!!\n\n");
          break;
        }
        case 2: {
          printf("Masukkan Umur yang Baru: \n");
          int newAge;
          scanf("%hd",&newAge);getchar();
          replace[i].age=newAge;
          print(replace[i]);
          printf("Data Berhasil Di rubah!!\n\n");
          break;
        }
        case 3:{
          printf("Masukkan Nomor Identifikasi yang Baru: \n");
          char newNI[15];
          scanf("%s", &newNI); getchar();
          while(strlen(newNI)!=10){
            printf("Nomor Identifikasi tidak valid \n");
            printf("Masukkan Nomor Identifikasi yang Baru: \n");
            scanf("%s", &newNI); getchar();
          }
          strcpy(replace[i].identificationNumber,newNI);
          print(replace[i]);
          printf("Data Berhasil Di rubah!!\n\n");
          break;
        }
        case 4:{
          printf("Masukkan Jabatan yang Baru: \n");
          char newPosition[15];
          scanf("%[^\n]", &newPosition); getchar();
          strcpy(replace[i].position,newPosition);
          print(replace[i]);
          printf("Data Berhasil Di rubah!!\n\n");
          break;
        }
        case 5:{
          printf("Masukkan Rating yang Baru: \n");
          char newRating;
          scanf("%c", &newRating); getchar();
          replace[i].employeeRank=newRating;
          print(replace[i]);
          printf("Data Berhasil Di rubah!!\n\n");
          break;
        }
        case 6:{
          printf("Masukkan Jam Kerja yang Baru: \n");
          int newWorkTime;
          scanf("%d", &newWorkTime); getchar();
          replace[i].worktime_per_week=newWorkTime;
          print(replace[i]);
          printf("Data Berhasil Di rubah!!\n\n");
          break;
      }

        case 7:{
          printf("Masukkan NIK yang Baru: \n");
          long long int newNIK;
          scanf("%lld", &newNIK); getchar();
          replace[i].nik=newNIK;
          print(replace[i]);
          printf("Data Berhasil Di rubah!!\n\n");
          break;
        }
        case 8:{
          printf("Masukkan Kewarganegaraan yang Baru(WNI/WNA): \n");
          char newWN[5];
          scanf("%s", &newWN); getchar();
          strcpy(replace[i].nationality,newWN);
          print(replace[i]);
          printf("Data Berhasil Di rubah!!\n\n");
          break;
        }
        case 9:{
          printf("Masukkan Alamat yang Baru: \n");
          char newAdress[200];
          scanf("%[^\n]", &newAdress); getchar();
          strcpy(replace[i].homeAdress,newAdress);
          print(replace[i]);
          printf("Data Berhasil Di rubah!!\n\n");
          break;
        }
        case 10:{
          printf("Masukkan Gaji yang Baru: \n");
          float newSalary;
          scanf("%f", &newSalary); getchar();
          replace[i].salary=newSalary;
          print(replace[i]);
          printf("Data Berhasil Di rubah!!\n\n");
          break;
        }
        case 11:{
          printf("Masukkan Sisa Cuti yang Baru: \n");
          int cuti;
          scanf("%d", &cuti); getchar();
          replace[i].holiday=cuti;
          print(replace[i]);
          printf("Data Berhasil Di rubah!!\n\n");
          break;
        }
      }
    }
  }
  freplace=fopen("DataBaseEmployee.txt", "w");
  for (int i=0;i<counter;i++){
      fprintf(freplace, "%s#%hd#%s#%s#%c#%d#%lld#%s#%s#%.2f#%d\n",
      replace[i].name,
      replace[i].age,
      replace[i].identificationNumber,
      replace[i].position,
      replace[i].employeeRank,
      replace[i].worktime_per_week,
      replace[i].nik,
      replace[i].nationality,
      replace[i].homeAdress,
      replace[i].salary,
      replace[i].holiday);
  }
  fclose(freplace);
  fclose(freplace);
}

void deleteData(){
  char remove[100];
  database hapus[500];
  int counter=0;
  int salah=0;
  printf("Ketik Nama Pegawai yang ingin dihapus:\n");
  scanf("%[^\n]", remove); getchar();
  FILE *fremove= fopen("DataBaseEmployee.txt", "r");
  for (int i=0;!feof(fremove);i++){
    fscanf(fremove, "%[^#]#%hd#%[^#]#%[^#]#%c#%d#%lld#%[^#]#%[^#]#%f#%d\n",
    hapus[i].name,
    &hapus[i].age,
    hapus[i].identificationNumber,
    hapus[i].position,
    &hapus[i].employeeRank,
    &hapus[i].worktime_per_week,
    &hapus[i].nik,
    hapus[i].nationality,
    hapus[i].homeAdress,
    &hapus[i].salary,
    &hapus[i].holiday); counter++;

    if(strcmp(remove,hapus[i].name)!=0){
      salah++;
    }
    if(strcmp(remove,hapus[i].name)==0){
      salah=0;
      print(hapus[i]);

      printf("Hapus Data ini?\n\n1.Ya\n2.Tidak\n");

    }
    }
    int choice;
    scanf("%d",&choice);getchar();

    if(choice==1){
      fremove=fopen("DataBaseEmployee.txt", "w");
      for (int i=0;i<counter;i++){
        if(strcmp(remove,hapus[i].name)==0){
          printf("\nData Berhasil Dihapus!!\n\n");
          continue;
        } if(strcmp(remove,hapus[i].name)!=0)
        {
          fprintf(fremove, "%s#%hd#%s#%s#%c#%d#%lld#%s#%s#%.2f#%d\n",
          hapus[i].name,
          hapus[i].age,
          hapus[i].identificationNumber,
          hapus[i].position,
          hapus[i].employeeRank,
          hapus[i].worktime_per_week,
          hapus[i].nik,
          hapus[i].nationality,
          hapus[i].homeAdress,
          hapus[i].salary,
          hapus[i].holiday);

        }
      }
      fclose(fremove);
    }
    else if(choice==2){
      printf("Data tidak terhapus\n\n");
    }

    fclose(fremove);

    if (salah==counter){
      printf("\nData tidak tersedia\n\n");
    }
}

void merge(database arr[], int left, int mid, int right){
  int leftSize=mid - left+1;
  int rightSize=right-mid;

  database leftArr[leftSize];
  database rightArr[rightSize];

  for(int i=0;i<leftSize;i++){
    leftArr[i]= arr[i+left];
  }
  for(int i=0;i<rightSize;i++){
    rightArr[i]= arr[i+mid+1];
  }

  int i=0,j=0,k=left;
  while(i < leftSize && j < rightSize){
        if(strcmp(leftArr[i].name,rightArr[j].name)>0){
            arr[k] = leftArr[i];
            k++;
            i++;
        }
        else{
            arr[k] = rightArr[j];
            k++;
            j++;
        }
    }
    while(i < leftSize){
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    while(j < rightSize){
        arr[k] = rightArr[j];
        j++;
        k++;
    }


}

void split(database arr[], int left,int right){
  if(left>=right){
    return;
  }

  int mid=(left+right)/2;
  split(arr,left,mid);
  split(arr,mid+1,right);

  merge(arr,left,mid,right);



}

void sortData(){
  database sort[500];
  FILE *fsort = fopen("./DataBaseEmployee.txt","r");
  int counter=0;
  database temp;
  for (int i=0;!feof(fsort);i++){
    fscanf(fsort, "%[^#]#%hd#%[^#]#%[^#]#%c#%d#%lld#%[^#]#%[^#]#%f#%d\n",
    sort[i].name,
    &sort[i].age,
    sort[i].identificationNumber,
    sort[i].position,
    &sort[i].employeeRank,
    &sort[i].worktime_per_week,
    &sort[i].nik,
    sort[i].nationality,
    sort[i].homeAdress,
    &sort[i].salary,
    &sort[i].holiday);
      counter++;
  }
   split(sort,0,counter);

  fsort=fopen("DataBaseEmployee.txt", "w");
  for (int i=counter;i>=0;i--){
    if(i==counter){
    } else {
      fprintf(fsort, "%s#%hd#%s#%s#%c#%d#%lld#%s#%s#%.2f#%d\n",
      sort[i].name,
      sort[i].age,
      sort[i].identificationNumber,
      sort[i].position,
      sort[i].employeeRank,
      sort[i].worktime_per_week,
      sort[i].nik,
      sort[i].nationality,
      sort[i].homeAdress,
      sort[i].salary,
      sort[i].holiday);

    }
  }
  fclose(fsort);
  fclose(fsort);
}

database searchData(){
  database temp;
  char search[100];
  database show;
  printf("Ketik Nama Pegawai yang ingin dilihat:\n");
  scanf("%[^\n]", search); getchar();
  FILE *fsearch= fopen("DataBaseEmployee.txt", "r");
  for (int i=0;!feof(fsearch);i++){
    fscanf(fsearch, "%[^#]#%hd#%[^#]#%[^#]#%c#%d#%lld#%[^#]#%[^#]#%f#%d\n",
    show.name,
    &show.age,
    show.identificationNumber,
    show.position,
    &show.employeeRank,
    &show.worktime_per_week,
    &show.nik,
    show.nationality,
    show.homeAdress,
    &show.salary,
    &show.holiday);
    if(strcmp(search,show.name)==0){
      return show;
    }
  }
  return temp;
 fclose(fsearch);
}

void inputData(){
  database employee;
  printf("- Masukkan Nama Lengkap Pegawai: \n");
  scanf("%[^\n]", employee.name); getchar();

  printf("\n- Masukkan Umur Pegawai: \n");
  scanf("%hd", &employee.age);

  printf("\n- Masukkan Nomor Identifikasi Pegawai (10 karakter): \n");
  scanf("%s", &employee.identificationNumber); getchar();
  while (strlen(employee.identificationNumber)!=10){

    printf("Nomor Identifikasi tidak valid\n");

    printf("\n- Masukkan Nomor Identifikasi Pegawai (10 karakter): \n");
    scanf("%s", &employee.identificationNumber); getchar();
  }


  printf("\n- Masukkan Jabatan Pegawai: \n");
  scanf("%[^\n]", employee.position);
  getchar();

  printf("\n- Masukkan Rating Pegawai(A-E): \n");
  scanf("%c", &employee.employeeRank);
  getchar();

  printf("\n- Masukkan Jam Kerja Pegawai: \n");
  scanf("%d", &employee.worktime_per_week);
  getchar();

  printf("\n- Masukkan NIK Pegawai (16 Karakter): \n");
  scanf("%lld", &employee.nik); getchar();

  printf("\n- Masukkan Kewarganegaraan Pegawai (WNI/WNA): \n");
  scanf("%[^\n]", employee.nationality); getchar();


  printf("\n- Masukkan Alamat Pegawai: \n");
  scanf("%[^\n]", employee.homeAdress); getchar();


  printf("\n- Masukkan Gaji Pegawai: \n");
  scanf("%f", &employee.salary); getchar();


  printf("\n- Masukkan Kuota Cuti Pegawai: \n");
  scanf("%d", &employee.holiday);

  FILE *fp=fopen("DataBaseEmployee.txt","a");
  printf("%d\n",fp);
  fprintf(fp, "%s#%hd#%s#%s#%c#%d#%lld#%s#%s#%.2f#%d\n",
    employee.name,
    employee.age,
    employee.identificationNumber,
    employee.position,
    employee.employeeRank,
    employee.worktime_per_week,
    employee.nik,
    employee.nationality,
    employee.homeAdress,
    employee.salary,
    employee.holiday);
    fclose(fp);

}

void view_All_Employees(){
   FILE *freadAll=fopen("DataBaseEmployee.txt", "r");
   database employee;
   while(!feof(freadAll)){

     fscanf(freadAll, "%[^#]#%hd#%[^#]#%[^#]#%c#%d#%lld#%[^#]#%[^#]#%f#%d\n",
     employee.name,
     &employee.age,
     employee.identificationNumber,
     employee.position,
     &employee.employeeRank,
     &employee.worktime_per_week,
     &employee.nik,
     employee.nationality,
     employee.homeAdress,
     &employee.salary,
     &employee.holiday);
       print(employee);


     }
     fclose(freadAll);
}

void app(){
  int choice;
    do{
        puts("1. Input Data Pegawai Baru");
        puts("2. Lihat Seluruh Data Pegawai");
        puts("3. Cari Data Pegawai");
        puts("4. Hapus Data Pegawai");
        puts("5. Ganti Data Pegawai");
        puts("6. Keluar");
        scanf("%d", &choice); getchar();
        switch(choice){
            case 1:{
                inputData();
                break;
            }
            case 2:{
              sortData();
                view_All_Employees();
                break;
            }
            case 3:{
              database show=searchData();
              if(show.nik == 0){
                printf("\nData tidak ditemukan\n\n");
              } else {
                print(show);
              }
                break;
            }

            case 4:{
              deleteData();
                break;
            }
            case 5:{
              replaceData();
                break;
            }
            default:{
              printf("Input tidak Valid\n");
            }
        }
    }while(choice != 6);
}

 int main(){
   app();
   return 0;
 }
