struct header_key   /* header key    */  {
                            /* off + size */ 
  int sizeof_hdr;           /* 0 + 4            */ 
  unsigned char data_type[10];       /* 4 + 10           */ 
  unsigned char db_name[18];         /* 14 + 18          */ 
  int extents;              /* 32 + 4           */ 
  short int session_error;  /* 36 + 2           */ 
  char regular;             /* 38 + 1           */ 
  char hkey_un0;            /* 39 + 1   */ 
};                          /* total=40 bytes */
struct image_dimension  {                                  
                               /* off + size       */ 
  short int dim[8];            /* 0 + 16           */ 
  unsigned char vox_units[4];  /* 16 + 4           */
  unsigned char cal_units[8];  /* 20 + 8           */
  short int datatype;          /* 30 + 2           */ 
  short int bitpix;            /* 32 + 2           */ 
  short int dim_un0;           /* 34 + 2           */ 
  float pixdim[8];             /* 36 + 32          */ 
                  /*  
                       pixdim[] specifies the voxel dimensitons:  
                       pixdim[1] - voxel width 
                       pixdim[2] - voxel height 
                       pixdim[3] - interslice distance 
                           ...etc 
                  */ 
  float vox_offset;     /* 68 + 4            */ 
  float funused1;       /* 72 + 4            */ 
  float funused2;       /* 76 + 4            */ 
  float funused3;       /* 80 + 4            */ 
  float cal_max;        /* 84 + 4            */ 
  float cal_min;        /* 88 + 4            */ 
  float compressed;     /* 92 + 4            */ 
  float verified;       /* 96 + 4            */ 
  int glmax,glmin;      /* 100 + 8           */ 
};                    /* total=108 bytes  */ 
struct data_history {                                  
                        /* off + size       */ 
  char descrip[80];     /* 0 + 80           */ 
  char aux_file[24];    /* 80 + 24         */ 
  char orient;          /* 104 + 1          */ 
  char originator[10];  /* 105 + 10         */ 
  char generated[10];   /* 115 + 10         */ 
  char scannum[10];     /* 125 + 10        */ 
  char patient_id[10];  /* 135 + 10         */ 
  char exp_date[10];    /* 145 + 10        */ 
  char exp_time[10];    /* 155 + 10        */ 
  char hist_un0[3];     /* 165 + 3          */ 
  int views;            /* 168 + 4          */ 
  int vols_added;       /* 172 + 4          */ 
  int start_field;      /* 176 + 4          */ 
  int field_skip;       /* 180 + 4         */ 
  int omax, omin;       /* 184 + 8         */ 
  int smax, smin;       /* 192 + 8         */ 
};
struct dsr {  
  struct header_key hk;       /* 0 + 40            */ 
  struct image_dimension dime;/* 40 + 108          */ 
  struct data_history hist;   /* 148 + 200         */ 
};                            /* total= 348 bytes */ 

