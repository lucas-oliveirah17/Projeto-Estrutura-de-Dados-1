# Projeto-Estrutura-de-Dados-1      
<h3>Projeto final da disciplina Estrutura de Dados 1 (GRUEDA1) - IFSP Guarulhos</h3>

<h4>🚀 PROJETO CONCLUÍDO! 🛠️</h4>
<h5>Colaboradores:</h5>
<ul>
  <li>Daniel Navarro Porto - https://github.com/danielnporto</li>
  <li>Lucas Silva de Oliveira - https://github.com/lucas-oliveirah17/</li>
</ul>

<h2>Lista de Contatos</h2>

<p>&nbsp;&nbsp;&nbsp;&nbsp&nbsp;&nbsp;&nbsp;&nbsp;A avaliação de nossa disciplina consistirá na elaboração de um programa para inserção,
controle e manipulação dos dados de uma lista de contatos de Clientes para a empresa fictícia ACME
S.A., que contará com informações tais como: número de identificação do cliente, nome do cliente,
empresa onde trabalha, departamento, telefones fixo, celular e e-mail.</p>

<p>&nbsp;&nbsp;&nbsp;&nbsp&nbsp;&nbsp;&nbsp;&nbsp;Seu programa deverá ser capaz de salvar e recuperar os dados gerados entre seções de
trabalho anteriores e atuais, além de possibilitar a inserção de novos clientes e remoção de clientes
existentes, edição dos dados de clientes já armazenados, e exibição dos dados de clientes.</p>

<p>&nbsp;&nbsp;&nbsp;&nbsp&nbsp;&nbsp;&nbsp;&nbsp;Ao final de uma seção de trabalho, o programa deverá salvar em arquivo o conteúdo da lista
de contatos da corrente seção, para a continuação do trabalho posteriormente em nova seção, que
por sua vez, recuperará os dados da seção anterior, e assim por diante.</p>

<hr>
<h3>Estruturas de dados do Aplicativo</h3>

<p>&nbsp;&nbsp;&nbsp;&nbsp&nbsp;&nbsp;&nbsp;&nbsp;Seu aplicativo deverá ser baseado no código da estrutura de dados do tipo Lista Dinâmica,
desenvolvida em sala de aula (<strong>REQUISITO</strong>). Deverá ter as suas funções que manipulam os dados de
entrada e saída, <strong>devidamente alteradas</strong> para que sejam pertinentes e estejam ajustadas aos
requisitos de seu programa.</p> 
  
<p>&nbsp;&nbsp;&nbsp;&nbsp&nbsp;&nbsp;&nbsp;&nbsp;Não é necessário implementar as funções de manipulação da lista não sejam úteis, tais como
inserções no início, remoções no final, etc. A ordenação dos elementos na lista deverá ser <strong>crescente</strong>
e baseada no atributo (campo) código, portanto, só há a <strong>necessidade de se contar com as funções
de inserção e remoção ordenadas</strong>. Ainda com relação ao atributo código, não deve ser
utilizado o incremento automático, e uma verificação de duplicidade deve ser realizada durante as
inserções de novos clientes.</p> 
  
<p>&nbsp;&nbsp;&nbsp;&nbsp&nbsp;&nbsp;&nbsp;&nbsp;A funcionalidade de gravação e recuperação de dados entre seções, deverá ser implementada
<strong>utilizando o modo gravação binária (REQUISITO)</strong>, salvando as estruturas (<strong>structs</strong>) completas, com
todos os dados dos clientes. Isso torna a recuperação dos dados mais simples.</p> 
  
<p>&nbsp;&nbsp;&nbsp;&nbsp&nbsp;&nbsp;&nbsp;&nbsp;Os nós da Lista Dinâmica deverão ter o formato abaixo para sua utilização na Lista Dinâmica:</p> 

<table>
  <tr>
    <th style="text-align: center;">Estrutura Cliente<br>(struct)</th>
    <th style="text-align: center;">Ponteiro<br>prox.</th>
  </tr>
  <tr>
    <td>Código</td>
    <td rowspan="7"">Ponteiro para a<br>próxima<br>estrutura</td>
  </tr>
  <tr>
    <td>Nome</td>
  </tr>
  <tr>
    <td>Empresa</td>
  </tr>
  <tr>
    <td>Departamento</td>
  </tr>
  <tr>
    <td>Telefone</td>
  </tr>
  <tr>
    <td>Celular</td>
  </tr>
  <tr>
    <td>E-mail</td>
  </tr>
</table>

<hr>
<h3>Funcionalidades do Aplicativo – o menu de opções</h3>
  
<p>&nbsp;&nbsp;&nbsp;&nbsp&nbsp;&nbsp;&nbsp;&nbsp;Todas as funcionalidades do seu programa deverão estar implementadas em funções que
realizarão apenas uma <strong>atividade específica por vez</strong>. Por exemplo, uma função para realizar a leitura
dos dados, uma para armazenamento dos dados em arquivo, uma para impressão em tela, uma para
edição, etc. <strong>Modularize</strong> seu programa.</p>

<p>&nbsp;&nbsp;&nbsp;&nbsp&nbsp;&nbsp;&nbsp;&nbsp;Seu aplicativo deverá contar com um menu, exibido de forma <strong>ininterrupta</strong>, e que terá suas
escolhas acessíveis por números, onde o usuário escolherá a opção que desejar apenas digitando o
número correspondente e confirmar teclando <em>enter</em>.</p>
  
<p>&nbsp;&nbsp;&nbsp;&nbsp&nbsp;&nbsp;&nbsp;&nbsp;Após finalização da execução de cada funcionalidade, o fluxo de execução seu programa deverá retornar
ao menu reapresentando-o, possibilitando então novas escolhas. O menu deverá contar ainda com
uma opção específica para encerramento da aplicação, lembrando que neste ponto deve-se tomar o
cuidado com a <strong>perda de dados.</strong></p>
  
<p>&nbsp;&nbsp;&nbsp;&nbsp&nbsp;&nbsp;&nbsp;&nbsp;O menu terá que contar no <strong>mínimo</strong>, com as seguintes opções:</p>

<ul>
  <li>Inserção de novo contato, verificando a duplicidade de códigos (não pode haver dois iguais);</li>
  <li>Gerar e exibir relatório de contatos em forma de lista total</li>
  <li>Gerar e exibir relatório individual com busca por identificador (código);</li>
  <li>Gerar e exibir relatório com busca por nome (neste caso exibir todos que tenham o mesmo
  nome utilizado na busca – Ex: busca = “José” – lista todos os clientes que possuam este mesmo
  nome);</li>
  <li>Edição de dados do contato, escolhido por identificador;</li>
  <li>Remover contato, escolhido por identificador;</li>
  <li>Sair e encerrar o programa, porém, antes de sua efetiva finalização, salvando toda a lista para posterior nova seção de
  trabalho.</li>
</ul>

<hr>
<h3>As opções do menu</h3>
  
<h4>Inserção de novo contato</h4>

<p>&nbsp;&nbsp;&nbsp;&nbsp&nbsp;&nbsp;&nbsp;&nbsp;Esta opção do menu tratará da inserção de novos clientes na aplicação. Antes da inserção,
uma busca deverá ser realizada na lista de contatos a procura de identificadores (código) duplicados.
Caso haja um cliente que possua o mesmo código já existente na lista, isso deverá ser informado ao
usuário para que mude-o ou então aborte a inserção. Estando validado o código (confirmação de não
duplicidade), seus dados deverão ser armazenados na estrutura especifica do “cliente”, que então
no momento da inserção na Lista será atribuída a parte de dados (do nó), que fará parte da Lista
Dinâmica.</p>

<h4>Geração de relatório – Lista Total</h4>

<p>&nbsp;&nbsp;&nbsp;&nbsp&nbsp;&nbsp;&nbsp;&nbsp;A aplicação deverá contar com uma listagem total em tela, na forma de relatório, com todos
os clientes armazenados na Lista Dinâmica. Nesta listagem será possível a verificação dos códigos dos
clientes, para posterior utilização em outras funcionalidades.</p>

<h4>Geração de relatório individual – busca por identificador</h4>

<p>&nbsp;&nbsp;&nbsp;&nbsp&nbsp;&nbsp;&nbsp;&nbsp;Este relatório funciona de forma individual para confirmação de dados de clientes específicos.
Informa-se o código de identificação, e então a aplicação exibe todos os dados daquele cliente para
consulta.</p>

<h4>Geração de relatório – busca por nome</h4>

<p>&nbsp;&nbsp;&nbsp;&nbsp&nbsp;&nbsp;&nbsp;&nbsp;De forma similar ao anterior, este relatório busca os clientes por nome, sendo também mais
uma forma de identificação dos clientes na base de dados. Vale ressaltar que nesta função é possível
encontrar <strong>mais de um cliente com o mesmo nome</strong>. Neste caso, <strong>todos com o mesmo nome</strong> devem
ser exibidos. Um detalhe dever ser observado: A linguagem C é <em><strong>Case Sensitive</strong></em>, tome cuidado com as
buscas.</p>

<h4>Edição de dados do contato – busca por identificador</h4>
 
<p>&nbsp;&nbsp;&nbsp;&nbsp&nbsp;&nbsp;&nbsp;&nbsp;Esta funcionalidade permite a busca, exibição e posterior edição de um cliente. Ela deve ser
disparada pelo fornecimento do código de identificação do cliente.</p>

<p>&nbsp;&nbsp;&nbsp;&nbsp&nbsp;&nbsp;&nbsp;&nbsp;Após o cliente ser encontrado na Lista onde está armazenado, seus dados devem ser exibidos
para confirmação, juntamente com a mensagem se o usuário realmente deseja editar seus dados.
Em caso afirmativo, a edição deve acontecer enquanto a <strong>aplicação ainda exibe os dados antigos</strong> por
uma questão facilitadora para a edição.</p>
  
<p>&nbsp;&nbsp;&nbsp;&nbsp&nbsp;&nbsp;&nbsp;&nbsp;Em caso negativo para a edição, a aplicação deverá simplesmente retornar ao menu principal.</p>

<h4>Remoção de contato – busca por identificador</h4>
  
<p>&nbsp;&nbsp;&nbsp;&nbsp&nbsp;&nbsp;&nbsp;&nbsp;O funcionamento desta opção do menu é similar ao anterior. A aplicação executará uma
busca pelo código de identificação do cliente armazenado na lista dinâmica, e em seguida exibirá os
dados do cliente em tela. Na sequência deverá exibir uma mensagem solicitando a confirmação de exclusão. Em
caso afirmativo, remove-o da Lista; em caso negativo nada realiza. Ao término de ambos os casos, a
aplicação retorna ao menu principal.</p>

<h4>Sair do programa – encerramento com segurança</h4>
 
<p>&nbsp;&nbsp;&nbsp;&nbsp&nbsp;&nbsp;&nbsp;&nbsp;Esta opção encerra a execução da aplicação Lista de Contatos. Porém antes do encerramento
do aplicativo, deve ser executada a rotina para a <strong>gravação de todos os dados</strong> que estão presentes
na Lista Dinâmica, para o arquivo de dados de forma que não haja <strong>perda de informações</strong>.</p>

<hr>
<h3>Regras:</h3>

<ul>
  <li>Implementar o código utilizando somente Linguagem C;</li>
  
  <li>Utilizar o código da estrutura de dados do tipo Lista Dinâmica apresentados em sala de aula
  – vetores convencionais para armazenamento dos dados dos clientes, a <strong>não utilização</strong> de
  alocações de memória, códigos de terceiros (pessoas estranhas ao nosso círculo ou <strong>Chat GPT</strong>),
  <strong>invalidam</strong> o projeto;</li>
  
  <li>O arquivo de dados salvos da lista de contatos, deverá entregue para avaliação juntamente
  com o aplicativo, possuindo no mínimo 10 registros de clientes previamente gravados para
  os testes funcionais de avaliação, assim como todos os arquivos gerados pela IDE CodeBlocks;</li>
  
  <li>Extremamente importante informar, com comentários, <strong>o que e como</strong> as rotinas (funções)
  funcionam (lembrem-se: eu não conheço o seu raciocínio, portanto comentem!!!), <strong>vale
  pontos</strong>;</li>
  
  <li><strong>Projetos copiados (e o Trabalho que serviu de fonte - inclusive) terão nota 0 – Lembre-se:
  todos os projetos de semestres anteriores estão arquivados e serão checados, além de
serem diferentes entre si</strong>;</li>
  
  <li>O projeto será realizado no máximo em duplas, que deverão ser informadas
  em planilha disponível no Moodle.</li>

  <li>Use o bom senso, faça o simples não complique! Implemente uma funcionalidade por vez,
  facilitando assim a correção dos possíveis erros durante o seu desenvolvimento.</li>
</ul>

<h4>O Trabalho deve ser entregue com:</h4>
<ul>
  <li><strong>Todos os arquivos do projeto</strong> (executáveis, fontes, bibliotecas, <strong>TODOS</strong> os arquivos gerados pela IDE
  CodeBlocks e módulos de funções), todos bem indentados e comentados quando for o caso,
  em data especificada na plataforma AVA/Moodle;</li>

  <li>Um relatório deverá ser entregue, em padrão ABNT juntamente com o projeto, em formato
  PDF (vale 2 pontos) e deverá conter:</li>

  <li style="list-style-type: none;">
    <ul>
      <li>Nome e prontuário dos integrantes da dupla.</li>
      <li>As decisões de implementação tomadas, uma visão geral do funcionamento do
      programa, resultado dos testes, quais foram os problemas, e como foram resolvidos,
      etc.</li>
    </ul>
  </li>
</ul>

<h3>Não há a possibilidade de alteração da data de entrega.</h3>

<hr>
<h3>Fluxograma de execução – Lista de contatos Dinâmica</h3>

![Fluxograma do Projeto](imagens/Fluxograma-Projeto.jpeg)

<h2>Instruções de Colaboração no GitHub para o Projeto</h2>

<h3>1. Clonando o Repositório</h3>
<p>Primeiro, todos os membros do grupo precisam clonar o repositório em suas máquinas locais. Para isso, use o seguinte comando no terminal:</p>

```bash
git clone git@github.com:lucas-oliveirah17/Projeto-Estrutura-de-Dados-1.git
```

<p>Isso cria uma cópia local do repositório em seu computador.</p>

<h3>2. Criando e Mudando para uma Nova Branch</h3>
Cada membro do grupo deve criar uma branch separada para fazer suas alterações, para evitar conflitos no código principal (geralmente chamado de main ou master). Para criar uma nova branch, use:

```bash
git checkout -b nome-da-branch
```

Substitua `nome-da-branch` por algo descritivo, como `adicionar-funcionalidade-x` ou `corrigir-bug-y`.

<h3>3. Fazendo Alterações no Repositório</h3>

<p>Após mudar para a sua branch, faça as alterações necessárias no código, nos arquivos de documentação ou em qualquer outra parte do repositório. Use o editor de sua preferência.</p>

<h3>4. Verificando as Alterações com git status</h3>

<p>Para verificar quais arquivos foram modificados, use o comando:</p>

```bash
git status
```

<h3>5. Adicionando e Comitando as Alterações</h3>

<p>Após fazer as alterações desejadas, adicione os arquivos modificados ao seu repositório local com o comando:</p>

```bash
git add .
```
<p>Em seguida, faça um commit para registrar as alterações:</p>

```bash
git commit -m "Descrição clara das alterações feitas"
```
<p>Use uma mensagem de commit significativa que explique o que você fez (exemplo: "Corrigir bug no processamento de dados").</p>

<h3>6. Atualizando a Branch Principal (Main)</h3>
Antes de enviar suas alterações para o GitHub, é importante garantir que sua branch está atualizada com a versão mais recente da branch principal (geralmente chamada de main ou master). Para isso, execute:

```bash
git checkout main
git pull origin main
git checkout nome-da-branch
git merge main
```

<p>Isso atualiza sua branch com as últimas alterações feitas por outros membros do grupo.</p>

<h3>7. Enviando suas Alterações para o GitHub</h3>
<p>Agora que sua branch está atualizada, você pode enviar suas alterações para o repositório no GitHub. Use o comando:</p>

```bash
git push origin nome-da-branch
```

<p>Isso envia sua branch e alterações para o GitHub.</p>

<h3>8. Criando um Pull Request (PR)</h3>
<p>Depois de enviar as alterações para o GitHub, você deve criar um Pull Request (PR) para que os outros membros do grupo revisem suas alterações antes de integrá-las à branch principal (main). Para isso, vá até a página do seu repositório no GitHub, clique em "Compare & Pull Request" ao lado da sua branch e depois em "Create Pull Request".</p>

<h3>9. Revisando e Aceitando Pull Requests</h3>
<p>Todos os membros do grupo devem revisar os Pull Requests dos outros. Quando estiverem prontos para ser incorporados, um membro do grupo (geralmente o responsável pela manutenção do projeto) pode aceitar o PR clicando em "Merge Pull Request".</p>

<h3>10. Mantendo o Repositório Local Atualizado</h3>
<p>Após a aprovação de um Pull Request e a atualização da branch main, todos os membros devem manter suas cópias locais atualizadas com o repositório remoto. Para fazer isso, execute os seguintes comandos:</p>

```bash
git checkout main
git pull origin main
```

<p>Isso vai garantir que todos tenham a versão mais recente do código.</p>

<h3>11. Resolvendo Conflitos</h3>
<p>Se houver conflitos de merge (quando duas pessoas editam o mesmo trecho de código), o Git pedirá para você resolver os conflitos manualmente. O Git irá marcar as áreas conflitantes no código, e você precisará editar essas partes do código para decidir qual versão deve ser mantida.</p>
<p>Após resolver os conflitos, adicione os arquivos e faça um novo commit:</p>

```bash
git add .
git commit -m "Resolver conflitos de merge"
```

Então, finalize o processo com um `git push`.

<hr>
<h3>Resumo do Fluxo de Trabalho</h3>
<ol>
  <li>Clone o repositório</li>
  
  <li>Crie uma nova branch: git checkout -b nome-da-branch</li>
  
  <li>Faça as alterações</li>
  <li>Verifique o status: git status</li>
  <li>Adicione os arquivos: git add .</li>
  <li>Comite as alterações: git commit -m "Descrição das alterações"</li>
  <li>Puxe as últimas alterações da branch principal: git pull origin main</li>
  <li>Envie suas alterações para o GitHub: git push origin nome-da-branch</li>
  <li>Crie um Pull Request no GitHub</li>
  <li>Revise e aceite Pull Requests</li>
  <li>Mantenha seu repositório local atualizado: git pull origin main</li>
</ol>

<hr>
<h3>Dicas Finais</h3>
<ul>
  <li><strong>Comunique-se bem:</strong> Sempre escreva mensagens de commit claras e significativas.</li>
  <li><strong>Evite trabalhar diretamente na branch main:</strong> Sempre crie uma branch para cada tarefa.</li>
  <li><strong>Peça revisão:</strong> Antes de mesclar qualquer PR, peça a outros membros do grupo para revisar o código.</li>
</ul>
