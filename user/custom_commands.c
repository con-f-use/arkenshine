#include "commonservices.h"

extern uint8_t last_leds[512*3];
extern int last_led_count;


int ICACHE_FLASH_ATTR CustomCommand(char * buffer, int retsize, char *pusrdata, unsigned short len)
{
	char * buffend = buffer;

	switch( pusrdata[1] ) {
    	case 'C': case 'c':  //Custom command test
    		buffend += ets_sprintf( buffend, "CC" );
    		return buffend-buffer;
    	break;

    	case 'l': case 'L': { //LED info
    		int i, it = 0;
    		buffend += ets_sprintf( buffend, "CL:%d:", last_led_count );
    		uint16_t toledsvals = last_led_count*3;
    		if( toledsvals > 600 ) toledsvals = 600;
    		for( i = 0; i < toledsvals; i++ ) {
    			uint8_t samp = last_leds[it++];
    			*(buffend++) = tohex1( samp>>4 );
    			*(buffend++) = tohex1( samp&0x0f );
    		}
    		return buffend-buffer;
    	} break;
#if 0
        case 'B': case 'b': { // Burn new pattern
            char * data = pusrdata + 2;
            uint32_t nbr_bytes = *((uint32_t*)data);   data+=4;

            uint32_t it;
            for(it=0; it<nbr_bytes; ++it )
                ;

            uint32_t cck_bytes = *((uint32_t*)data);
            if( cck_bytes != nbr_bytes )
                printf("Validation error!\n");

            // EnterCritical();
            // spi_flash_write( nr, (uint32*)buffer, (datlen/4)*4 );
            // ExitCritical();
        } break;
#endif
	}
	return -1;
}
