int gsm_wait_response(char *expected, unsigned int timeout_ms)
{
    unsigned int t = 0;
    while(t < timeout_ms)
    {
        if(gsm_flag)
        {
            gsm_flag = 0;
            if(strstr(gsm_buff, expected))
                return 1;
        }
        delay_ms(10);
        t += 10;
    }
    return 0;
}

// ---------------- GSM FUNCTIONS ----------------

int init_gsm(void)
{
    gsm_send_cmd("AT");
    if(!gsm_wait_response("OK", 2000)) return 0;

    gsm_send_cmd("ATE0");   // echo off
    if(!gsm_wait_response("OK", 2000)) return 0;

    gsm_send_cmd("AT+CMGF=1");  // SMS text mode
    if(!gsm_wait_response("OK", 2000)) return 0;

    return 1;   // success
}

int send_sms(char *num, char *msg)
{
    char cmd[32];

    // Send AT+CMGS command
    sprintf(cmd, "AT+CMGS=\"%s\"", num);
    gsm_send_cmd(cmd);
     if(!gsm_wait_response(">", 3000)) return 0;

    // Send message
    uart_str(msg);

    // End with Ctrl+Z (ASCII 26)
    uart_tx(26);

    if(!gsm_wait_response("OK", 5000)) return 0;

    return 1;  // success
}

// ---------------- MAIN ----------------

int main(void)
{
    uart_init();
    delay_ms(2000);

    if(init_gsm())
        uart_str("GSM INIT DONE\r\n");
    else
        uart_str("GSM INIT FAIL\r\n");

    int temp = 45;  // Example threshold test

    if(temp > 40)
    {
        if(send_sms("+919876543210", "Temperature High!"))
            uart_str("SMS SENT\r\n");
        else
            uart_str("SMS FAIL\r\n");
    }

    while(1);
}

                         
