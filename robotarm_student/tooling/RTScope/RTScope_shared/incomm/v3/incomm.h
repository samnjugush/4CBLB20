
/* prototypes */
int incomm_server_open(int);
int incomm_server_read(void*,int);
int incomm_server_write(void*,int);
int incomm_server_close(void);
int incomm_server_close2(void);

int incomm_client_open(int);
int incomm_client_read(void*,int);
int incomm_client_write(void*,int);
int incomm_client_close(void);
