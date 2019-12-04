# Gerenciamento de Biblioteca
## User Stories
### User Story 01:
<p>Como um leitor da biblioteca eu gostaria de buscar um livro para achar sua localização física.</p>
<p><b>Critérios de aceitação:</b></p>
<p>Busca de um livro por título;</p>
<p>Busca deve retornar em qual estante e qual quarto está o livro, ou se está alugado;</p>
<p>Busca deve retornar todas as informações do livro (título, autor);</p>
<p>Alugar um livro deve alterar a situação dele de forma que identifique que está locado e por quem ele foi locado;</p>

### User Story 02:
<p>Como um usuário Premium da biblioteca eu gostaria de locar quantos livros eu quiser.</p>
<p><b>Critérios de aceitação:</b></p>
<p>Locar número ilimitado de livros sem gerar erros;</p>

### User Story 03:
<p>Como um usuário Premium da biblioteca eu gostaria de ter acessos a livros, mesmo que limitado, sem ter que pagar pela minha conta.</p>
<p><b>Critérios de aceitação:</b></p>
<p>Locar número limitado de livros sem gerar erros;</p>
<p>Não permitir locação de livros acima do limite;</p>


### User Story 04:
<p>Como um organizador da biblioteca eu gostaria de registrar um novo leitor para que ele possa utilizar a biblioteca;</p>
<p><b>Critérios de aceitação:</b></p> 
<p>O novo usuário tem que ter nome;</p>
<p>Uma ID de usuário deve ser gerada;</p>
<p>Deve-se informar ao sistema se o usuário pode também fazer o papel de organizador ou só de leitor;</p>

## Cartões CRC:

<table>
  <tr>
    <th>Classe:  Usuário</th>
    <th> </th>
  </tr>
  <tr>
    <td><b>Responsabilidades</b></td>
    <td><b>Colaborações</b></td>
  </tr>
  <tr>
    <td>Username</td>
    <td>Free</td>
  </tr>
  <tr>
    <td>Nome</td>
    <td>Organizador</td>
  </tr>
  <tr>
    <td>Lista de Livros Alugados</td>
    <td>Premium</td>
  </tr>
   <tr>
    <td>Lista de Livros Alugados</td>
    <td>Livro</td>
  </tr>
</table>

<table>
  <tr>
    <th>Classe:  Free</th>
    <th> </th>
  </tr>
   <tr>
    <td><b>Responsabilidades</b></td>
    <td><b>Colaborações</b></td>
  </tr>
  <tr>
    <td>Nome </td>
    <td>Livro </td>
  </tr>
  <tr>
    <td>Username</td>
    <td>Organizador </td>
  </tr>
  <tr>
    <td>Livros Alugados </td>
    <td> </td>  
  </tr>
  <tr>
    <td>Alugar Livro </td>
    <td> </td>
  </tr>
  <tr>
    <td>Devolver Livro </td>
    <td> </td>
  </tr>
</table>

<table>
  <tr>
    <th>Classe:  Premium</th>
    <th> </th>
  </tr>
   <tr>
    <td><b>Responsabilidades</b></td>
    <td><b>Colaborações</b></td>
  </tr>
  <tr>
    <td>Nome </td>
    <td>Livro </td>
  </tr>
  <tr>
    <td>Username</td>
    <td>Organizador </td>
  </tr>
  <tr>
    <td>Livros Alugados </td>
    <td> </td>  
  </tr>
  <tr>
    <td>Alugar Livro </td>
    <td> </td>
  </tr>
  <tr>
    <td>Devolver Livro </td>
    <td> </td>
  </tr>
</table>

<table>
  <tr>
    <th>Classe:  Organizador</th>
    <th> </th>
  </tr>
   <tr>
    <td><b>Responsabilidades</b></td>
    <td><b>Colaborações</b></td>
  </tr>
  <tr>
    <td>Nome </td>
    <td>Livro </td> 
  </tr>
  <tr>
    <td>Username </td>
    <td> </td>
  </tr>
  <tr>
    <td>Registrar Usuário </td>
    <td> </td>
  </tr>
</table>
<table>
  <tr>
    <th>Classe:  Livro</th>
    <th> </th>
  </tr>
   <tr>
    <td><b>Responsabilidades</b></td>
    <td><b>Colaborações</b></td>
  </tr>
  <tr>
    <td>Título </td>
    <td>Premium </td>
  </tr>
  <tr>
    <td>Autor </td>
    <td>Free</td>
  </tr>
  <tr>
    <td>Localização </td>
    <td>Organizador </td>
  </tr>
  <tr>
    <td>Locado Por</td>
    <td> </td>
  </tr>
</table>

## Implementação
### Usuários
<p>Nesta biblioteca existem diferentes tipos de usuários: Organizadores, que além de alugar livros também cadastram outros usuários, Premium, que podem alugar quantos livros quiserem e Free, que tem um limite de locação de três livros. Para a implementação desses diferentes tipos foi criada uma classa mãe, Usuário, e as demais categorias foram colocadas como classes filhas.</p>

<h4> Classe Usuário </h4>
<p>É a classe mãe de todos os tipos de usuário, utilizada para manter em um só lugar os atributos e as funções comuns a todos os outros tipos de usuários</p>

<p><b>Atributos</b></p>
<p>username: uma string que contém o username do usuário</p>
<p>nome: uma string que contém o nome do usuário</p>
<p>livros_alugados: um vetor de strings que contém os livros que o usuário tem consigo</p>

<p><b>Métodos</b></p>
<p>Construtores que recebe tanto nenhum parâmetro, como de parâmetro todos os atributos</p>
<p>Destrutor default </p>
<p>getters e setters para todos os atributos</p>
<p>fazerLogin(std::string username): Método virtual puro implementado nas classes filhas</p>
<p>fazerLogin(std::string username, std::string filepath): Método que busca o usuário pelo username na base de dados passada pelo filepath, cada tipo de usuário tem um arquivo diferente como base de dados, e atualiza o valor de seus atributos dado o resultado da busca. Essa função é chamada dentro da implementação de fazerLogin(std::string username) de cada uma das classes filhas passando o filepath correspondente a base de dados daquela classe</p>
<p>alugarLivro(Livro livro): Método virtual puro implementado nas classes filhas</p>
<p>devolverLivro(Livro livro): Método virtual puro implementado nas classes filhas</p>

<h4> Classe Premium </h4>
<p>É a classe de usuários que pagaram por uma assinatura, podendo assim alugar uma quantidade ilimitada de livros</p>

<p><b>Atributos</b></p>
<p>Apenas os herdados da classe mãe</p>

<p><b>Métodos</b></p>
<p>Construtores que recebe tanto nenhum parâmetro, como de parâmetro todos os atributos</p>
<p>Destrutor default </p>
<p>fazerLogin(std::string username): Override de método virtual da classe mãe, passa o username e o lugar do arquivo que contém a base de dados dos usuários premium para a função fazerLogin(std::string username, std::string filepath) implementada na classe mãe</p>
<p>alugarLivro(Livro livro): Override de método virtual da classe mãe, busca o livro na base de dados e, caso ele não esteja alugado, aluga ele para o usuário, mudando tanto o atributo livros_alugados, quanto nas bases de dados de livros e de usuários premium</p>
<p>devolverLivro(Livro livro): Override de método virtual da classe mãe, retira o livro tanto do atributo livros_alugados, quanto nas bases de dados de livros e de usuários premium</p>

<h4> Classe Free </h4>
<p>É a classe de usuários que não pagaram por uma assinatura, podendo assim alugar apenas três livros</p>

<p><b>Atributos</b></p>
<p>Apenas os herdados da classe mãe</p>

<p><b>Métodos</b></p>
<p>Construtores que recebe tanto nenhum parâmetro, como de parâmetro todos os atributos</p>
<p>Destrutor default </p>
<p>fazerLogin(std::string username): Override de método virtual da classe mãe, passa o username e o lugar do arquivo que contém a base de dados dos usuários free para a função fazerLogin(std::string username, std::string filepath) implementada na classe mãe</p>
<p>alugarLivro(Livro livro): Override de método virtual da classe mãe, busca o livro na base de dados e, caso ele não esteja alugado e o usuário não tenha alugado um total de três livros, aluga ele para o usuário, mudando tanto o atributo livros_alugados, quanto nas bases de dados de livros e de usuários free</p>
<p>devolverLivro(Livro livro): Override de método virtual da classe mãe, retira o livro tanto do atributo livros_alugados, quanto nas bases de dados de livros e de usuários free</p>

<h4> Classe Organizador </h4>
<p>É a classe de usuários que atuam como administradores, podendo assim alugar quantos livros quiserem além de cadastrar novos usuários</p>

<p><b>Atributos</b></p>
<p>Apenas os herdados da classe mãe</p>

<p><b>Métodos</b></p>
<p>Construtores que recebe tanto nenhum parâmetro, como de parâmetro todos os atributos</p>
<p>Destrutor default </p>
<p>fazerLogin(std::string username): Override de método virtual da classe mãe, passa o username e o lugar do arquivo que contém a base de dados dos usuários organizadores para a função fazerLogin(std::string username, std::string filepath) implementada na classe mãe</p>
<p>alugarLivro(Livro livro): Override de método virtual da classe mãe, busca o livro na base de dados e, caso ele não esteja alugado e o usuário não tenha alugado um total de três livros, aluga ele para o usuário, mudando tanto o atributo livros_alugados, quanto nas bases de dados de livros e de usuários organizadores</p>
<p>devolverLivro(Livro livro): Override de método virtual da classe mãe, retira o livro tanto do atributo livros_alugados, quanto nas bases de dados de livros e de usuários organizadores</p>
<p>cadastrarNovoUsuario(std::string username, std::string nome, int tipo): recebe username, nome e tipo de usuário do usuário a ser cadastrado, busca o usuário na base de dados geral (que contém apenas username e tipo de cada usuario), caso não encontre chama a função que cria o novo usuário daquela categoria determinada</p>
<p>cadastrarNovoOrganizador(std::string username, std::string nome): insere usuário no banco de dados de organizadores e no banco de dados geral</p>
<p>cadastrarNovoPremium(std::string username, std::string nome): insere usuário no banco de dados de usuários premium e no banco de dados geral</p>
<p>cadastrarNovoFree(std::string username, std::string nome): insere usuário no banco de dados de usuários free e no banco de dados geral</p>

### Classe Livro
<p>Esta classe serve para armazenar as informações das obras contidas na biblioteca.</p>

<h4>Atributos</h4>
<p>titulo: string que armazena o titulo do livro</p>
<p>autor: string que armazena o autor da obra</p>
<p>localizacao: string que guarda a localização física do livro</p>
<p>alugado_por: string que contém quem está com o livro alugado</p>

<h4>Métodos</h4>
<p>Construtores que recebe tanto nenhum parâmetro, como de parâmetro todos os atributos</p>
<p>Destrutor default </p>
<p>getters e setters para todos os atributos</p>

### Biblioteca Csv
<p>Esta é uma biblioteca que implementa funções úteis que manipulam os arquivos .csv que são usados como base de dados para as informações tanto de usuários quanto de livros</p>

<h4>Funções</h4>
<p>parse_csv(std::string path_arquivo): lê o arquivo e retorna um vetor de vetor de strings, onde cada vetor de strings é uma linha do arquivo, cada string sendo uma informação de um dos campos</p>
<p>encontrarUsuario (std::string username, std::string filepath): retorna um vetor de strings que representa o usuário no banco de dados, ele procura no arquivo passado pela string filepath pelo username, também passado pelo parâmetro, isso é possível pois em todos os arquivos de usuário a coluna de username está na mesma posição</p>
<p>insereUsuario(std::string username, std::string nome, std::string filepath): insere as informações do usuário, com o livros_alugados sendo considerado vazio, no final do arquivo determinado por filepath, usado para os arquivos de um tipo de usuário específico, pois todos tem o mesmo formato</p>
<p>insereUsuario(std::string username, std::string filepath, int tipo): método utilizado para inserir um usuário no final do arquivo da base de dados geral</p>
<p>encontraLivroPorTitulo(std::string titulo): retorna vetor de string wue representa a linha ocupada pelo livro na base de dados, contendo as informações do mesmo</p>
<p>atualiza_csv(std::vector<std::vector<std::string>> dados ,std::string path_arquivo): recebe uma linha com as informações a serem atualizadas e atualiza essa linha no arquivo passado pelo path_arquivo</p>
<p>alugaLivro(std::string username, std::string titulo, std::string filepath): muda a informação de alugado_por na base de dados do livro passado para o username passado</p>
<p>devolveLivro(std::string username, std::string titulo, std::string filepath): atualiza as informações do livro removendo o username de quem tinha alugado o livro</p>
