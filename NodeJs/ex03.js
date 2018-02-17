const explorador= require('fs'); // Módulo para manipular o sistema de arquivos

const sistema=require('os'); //Módulo para recuperar informações do Sistema Operacional

var usuario=sistema.userInfo(); //Recuperar as informações do usuário logado

explorador.appendFile('arquivo.txt','\nUsuário:'+usuario.username);
/* Escreve no arquivo arquivo.text o nome do usuário.
Se o arquivo não existir ele será criado. Caso exista, a string é concatenada ao conteuúdo */
