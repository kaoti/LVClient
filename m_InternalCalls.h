#pragma once
#include "m_GlobalHeader.h"
class m_InternalCalls{
	void Update() {

        CURL* curl;
        CURLcode res;

        curl = curl_easy_init();
        if (curl) {
            curl_easy_setopt(curl, CURLOPT_URL, "https://secure.louisvuitton.com/ajaxsecure/getStockLevel.jsp?storeLang=esp-es&skuIdList=M69138");
            struct curl_slist* m_HeaderObject = NULL;
            m_HeaderObject = curl_slist_append(m_HeaderObject, "user-agent: Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/80.0.3987.163 Safari/537.36");
            m_HeaderObject = curl_slist_append(m_HeaderObject, "accept-language: es-ES,es;q=0.9,en-US;q=0.8,en;q=0.7");
            m_HeaderObject = curl_slist_append(m_HeaderObject, "Accept: application/json");
            m_HeaderObject = curl_slist_append(m_HeaderObject, "Content-Type: application/json");
            m_HeaderObject = curl_slist_append(m_HeaderObject, "Content-Encoding: gzip");
            curl_easy_setopt(curl, CURLOPT_HTTPHEADER, m_HeaderObject);


            res = curl_easy_perform(curl);


            /* always cleanup */
            curl_easy_cleanup(curl);
        }
	}
};

