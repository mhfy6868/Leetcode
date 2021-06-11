# [pip is configured with locations that require TLS/SSL, however the ssl module in Python is not available](https://stackoverflow.com/questions/45954528/pip-is-configured-with-locations-that-require-tls-ssl-however-the-ssl-module-in)





https://stackoverflow.com/questions/45954528/pip-is-configured-with-locations-that-require-tls-ssl-however-the-ssl-module-in/62264725#62264725



```
16

I'm using Windows 10 and installed Miniconda 3 with Python 3.7.

I solved this error by following this https://github.com/conda/conda/issues/8273

Specifically, I copied the following files from C:\Users\MyUser\Miniconda3\Library\bin to C:\Users\MyUser\Miniconda3\DLLs:

libcrypto-1_1-x64.dll
libcrypto-1_1-x64.pdb
libssl-1_1-x64.dll
libssl-1_1-x64.pdb
```

