module file

// #################### NXC Loader module ####################

// Constant offsets into the Loader module IOMAP structure. 
#define 	file__offset_p_func        		LoaderOffsetPFunc        
#define 	file__offset_free_user_flash	LoaderOffsetFreeUserFlash

// Error codes returned by functions in the Loader module (file access). 
#define 	file__success            		LDR_SUCCESS                
#define 	file__inprogress         		LDR_INPROGRESS                
#define 	file__reqpin             		LDR_REQPIN                
#define 	file__nomorehandles      		LDR_NOMOREHANDLES                
#define 	file__nospace            		LDR_NOSPACE                
#define 	file__nomorefiles        		LDR_NOMOREFILES                
#define 	file__eofexpected        		LDR_EOFEXPECTED                
#define 	file__endoffile          		LDR_ENDOFFILE                
#define 	file__notlinearfile      		LDR_NOTLINEARFILE                
#define 	file__filenotfound       		LDR_FILENOTFOUND                
#define 	file__handlealreadyclosed		LDR_HANDLEALREADYCLOSED                
#define 	file__nolinearspace      		LDR_NOLINEARSPACE                
#define 	file__undefinederror     		LDR_UNDEFINEDERROR                
#define 	file__fileisbusy         		LDR_FILEISBUSY                
#define 	file__nowritebuffers     		LDR_NOWRITEBUFFERS                
#define 	file__appendnotpossible  		LDR_APPENDNOTPOSSIBLE                
#define 	file__fileisfull         		LDR_FILEISFULL                
#define 	file__fileexists         		LDR_FILEEXISTS                
#define 	file__modulenotfound     		LDR_MODULENOTFOUND                
#define 	file__outofboundary      		LDR_OUTOFBOUNDARY                
#define 	file__illegalfilename    		LDR_ILLEGALFILENAME                
#define 	file__illegalhandle      		LDR_ILLEGALHANDLE                
#define 	file__btbusy             		LDR_BTBUSY                
#define 	file__btconnectfail      		LDR_BTCONNECTFAIL                
#define 	file__bttimeout          		LDR_BTTIMEOUT                
#define 	file__filetx_timeout     		LDR_FILETX_TIMEOUT                
#define 	file__filetx_dstexists   		LDR_FILETX_DSTEXISTS                
#define 	file__filetx_srcmissing  		LDR_FILETX_SRCMISSING                
#define 	file__filetx_streamerror 		LDR_FILETX_STREAMERROR                
#define 	file__filetx_closeerror  		LDR_FILETX_CLOSEERROR                
#define 	file__invalidseek        		LDR_INVALIDSEEK               

// Constants defining the functions provided by the Loader module.
#define 	file__cmd_openread       		LDR_CMD_OPENREAD             
#define 	file__cmd_openwrite      		LDR_CMD_OPENWRITE             
#define 	file__cmd_read           		LDR_CMD_READ             
#define 	file__cmd_write          		LDR_CMD_WRITE             
#define 	file__cmd_close          		LDR_CMD_CLOSE             
#define 	file__cmd_delete         		LDR_CMD_DELETE             
#define 	file__cmd_findfirst      		LDR_CMD_FINDFIRST             
#define 	file__cmd_findnext       		LDR_CMD_FINDNEXT             
#define 	file__cmd_versions       		LDR_CMD_VERSIONS             
#define 	file__cmd_openwritelinear		LDR_CMD_OPENWRITELINEAR             
#define 	file__cmd_openreadlinear 		LDR_CMD_OPENREADLINEAR             
#define 	file__cmd_openwritedata  		LDR_CMD_OPENWRITEDATA             
#define 	file__cmd_openappenddata 		LDR_CMD_OPENAPPENDDATA             
#define 	file__cmd_cropdatafile   		LDR_CMD_CROPDATAFILE             
#define 	file__cmd_findfirstmodule		LDR_CMD_FINDFIRSTMODULE             
#define 	file__cmd_findnextmodule 		LDR_CMD_FINDNEXTMODULE             
#define 	file__cmd_closemodhandle 		LDR_CMD_CLOSEMODHANDLE             
#define 	file__cmd_iomapread      		LDR_CMD_IOMAPREAD             
#define 	file__cmd_iomapwrite     		LDR_CMD_IOMAPWRITE             
#define 	file__cmd_bootcmd        		LDR_CMD_BOOTCMD             
#define 	file__cmd_setbrickname   		LDR_CMD_SETBRICKNAME             
#define 	file__cmd_btgetadr       		LDR_CMD_BTGETADR             
#define 	file__cmd_deviceinfo     		LDR_CMD_DEVICEINFO             
#define 	file__cmd_deleteuserflash		LDR_CMD_DELETEUSERFLASH             
#define 	file__cmd_pollcmdlen     		LDR_CMD_POLLCMDLEN             
#define 	file__cmd_pollcmd        		LDR_CMD_POLLCMD             
#define 	file__cmd_renamefile     		LDR_CMD_RENAMEFILE             
#define 	file__cmd_btfactoryreset 		LDR_CMD_BTFACTORYRESET             
#define 	file__cmd_resizedatafile 		LDR_CMD_RESIZEDATAFILE             
#define 	file__cmd_seekfromstart  		LDR_CMD_SEEKFROMSTART             
#define 	file__cmd_seekfromcurrent		LDR_CMD_SEEKFROMCURRENT             
#define 	file__cmd_seekfromend    		LDR_CMD_SEEKFROMEND            

// Constants that are part of the NXT firmware's Loader module. 
#define 	eof 			EOF
#define 	nxtl			NULL
#define		end_of_file		EOF



fn init() {

}