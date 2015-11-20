#include <string.h>
#include <curl/curl.h>

#define FEED_SIZE 1000000

CURL *curl;
CURLcode res;

char get_content[FEED_SIZE] = "";
int get_status = 0;

int get_writer(char* data, size_t size, size_t nmemb, void *userp) {
    strcat(get_content, data);
    return size * nmemb;
}

void get(char* url, char* data) {
    if(get_status == 0) {
        curl_global_init(CURL_GLOBAL_DEFAULT);
        curl = curl_easy_init();

        get_status = 1;
    }

    curl_easy_setopt(curl, CURLOPT_URL, url);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, get_writer);
    res = curl_easy_perform(curl);

    if(res != CURLE_OK) {
        fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        curl_easy_cleanup(curl);
    }

    curl_global_cleanup();
    strcpy(data, get_content);
}
