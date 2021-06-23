-- phpMyAdmin SQL Dump
-- version 4.6.4
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Generation Time: 07-Set-2017 às 22:50
-- Versão do servidor: 5.7.14
-- PHP Version: 5.6.25

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `projeto`
--

-- --------------------------------------------------------

--
-- Estrutura da tabela `agendamento`
--

CREATE TABLE `agendamento` (
  `id_agendamento` int(11) NOT NULL,
  `cliente` int(11) NOT NULL,
  `mes` int(11) NOT NULL,
  `dia` int(11) NOT NULL,
  `hora_inicio` varchar(200) NOT NULL,
  `hora_fim` varchar(200) NOT NULL
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

--
-- Extraindo dados da tabela `agendamento`
--

INSERT INTO `agendamento` (`id_agendamento`, `cliente`, `mes`, `dia`, `hora_inicio`, `hora_fim`) VALUES
(1, 1, 8, 3, '12:30', '16:40'),
(2, 2, 8, 23, '13', '15'),
(3, 1, 4, 23, '16', '18'),
(4, 17, 6, 12, '12', '14'),
(5, 27, 9, 6, '16', '18'),
(6, 28, 9, 7, '17', '18'),
(7, 5, 9, 7, '17', '18'),
(8, 29, 9, 7, '18', '19'),
(9, 29, 9, 7, '17', '18');

-- --------------------------------------------------------

--
-- Estrutura da tabela `avulsa`
--

CREATE TABLE `avulsa` (
  `id_avulsa` int(11) NOT NULL,
  `avulsa_cliente` int(11) NOT NULL,
  `avulsa_produto` int(11) NOT NULL,
  `avulsa_quantidade` int(11) NOT NULL,
  `avulsa_status` int(11) NOT NULL
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Extraindo dados da tabela `avulsa`
--

INSERT INTO `avulsa` (`id_avulsa`, `avulsa_cliente`, `avulsa_produto`, `avulsa_quantidade`, `avulsa_status`) VALUES
(1, 1, 2, 3, 1),
(2, 1, 2, 3, 1),
(3, 2, 1, 4, 2),
(4, 1, 2, 3, 1),
(5, 1, 1, 30, 1),
(6, 2, 1, 20, 2),
(7, 2, 2, 50, 2),
(8, 6, 2, 2, 1),
(9, 4, 2, 1, 1),
(10, 6, 2, 2, 1);

-- --------------------------------------------------------

--
-- Estrutura da tabela `cliente`
--

CREATE TABLE `cliente` (
  `id_cliente` int(11) NOT NULL,
  `nome` varchar(200) NOT NULL,
  `telefone` varchar(200) NOT NULL
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

--
-- Extraindo dados da tabela `cliente`
--

INSERT INTO `cliente` (`id_cliente`, `nome`, `telefone`) VALUES
(1, 'Luiz Tadeu', '99115-9884'),
(2, 'Lucas William', '99876-0909'),
(6, 'Natalia G L.', '545654'),
(17, 'Felipe Malcher', '56456456'),
(16, 'Roberto C++', '85786-5675'),
(4, 'Palmeiras NTM', '345'),
(19, 'Martinho S L.', '45656'),
(20, 'outro teste da silva xavier', '5645645'),
(21, 'tadeu teste final', '5756-3534'),
(22, 'teste do banco de dados da silva', '991559090'),
(23, 'Logan Wolverine', '46456'),
(24, 'Professor Xavier', '345345345'),
(25, 'Luan Carlos', '4345345'),
(26, 'Tadeu teste final', '93 991559884'),
(27, 'Artur SOBRINHO', '93991234567'),
(28, 'Lucas Wiliam', '63992801055'),
(29, 'marceleno', '93999999999');

-- --------------------------------------------------------

--
-- Estrutura da tabela `pdv`
--

CREATE TABLE `pdv` (
  `id_venda` int(11) NOT NULL,
  `pdv_cliente` int(11) NOT NULL,
  `pdv_produto` int(11) NOT NULL,
  `pdv_quantidade` int(11) NOT NULL,
  `pdv_status` int(11) NOT NULL
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Extraindo dados da tabela `pdv`
--

INSERT INTO `pdv` (`id_venda`, `pdv_cliente`, `pdv_produto`, `pdv_quantidade`, `pdv_status`) VALUES
(1, 1, 2, 3, 1),
(2, 1, 2, 3, 1),
(3, 2, 1, 4, 2),
(4, 1, 2, 3, 1),
(5, 1, 1, 30, 1),
(6, 2, 1, 20, 2),
(7, 2, 2, 50, 2),
(8, 6, 2, 2, 2),
(9, 4, 2, 1, 2),
(10, 6, 2, 2, 2),
(12, 27, 1, 2, 2),
(13, 27, 3, 1, 2),
(14, 29, 4, 1, 2);

-- --------------------------------------------------------

--
-- Estrutura da tabela `produto`
--

CREATE TABLE `produto` (
  `id_produto` int(11) NOT NULL,
  `nome_produto` varchar(200) NOT NULL,
  `valor_produto` float NOT NULL
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Extraindo dados da tabela `produto`
--

INSERT INTO `produto` (`id_produto`, `nome_produto`, `valor_produto`) VALUES
(1, 'agua mineral 500ml', 2),
(2, 'coca-cola 350ml', 3),
(3, 'kit recruta', 20),
(4, 'kit soldado', 30),
(5, 'kit sargento', 40),
(6, 'Recarga 50bolas', 10);

-- --------------------------------------------------------

--
-- Estrutura da tabela `usuario`
--

CREATE TABLE `usuario` (
  `id_usuario` int(11) NOT NULL,
  `nome` varchar(200) NOT NULL,
  `senha` varchar(200) NOT NULL
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

--
-- Extraindo dados da tabela `usuario`
--

INSERT INTO `usuario` (`id_usuario`, `nome`, `senha`) VALUES
(1, 'tadeu', 'tadeu'),
(2, 'malcher', 'malcher'),
(3, 'lucas', 'lucas'),
(4, 'natalia', 'natalia');

--
-- Indexes for dumped tables
--

--
-- Indexes for table `agendamento`
--
ALTER TABLE `agendamento`
  ADD PRIMARY KEY (`id_agendamento`),
  ADD KEY `cliente` (`cliente`);

--
-- Indexes for table `avulsa`
--
ALTER TABLE `avulsa`
  ADD PRIMARY KEY (`id_avulsa`);

--
-- Indexes for table `cliente`
--
ALTER TABLE `cliente`
  ADD PRIMARY KEY (`id_cliente`);

--
-- Indexes for table `pdv`
--
ALTER TABLE `pdv`
  ADD PRIMARY KEY (`id_venda`);

--
-- Indexes for table `produto`
--
ALTER TABLE `produto`
  ADD PRIMARY KEY (`id_produto`);

--
-- Indexes for table `usuario`
--
ALTER TABLE `usuario`
  ADD PRIMARY KEY (`id_usuario`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `agendamento`
--
ALTER TABLE `agendamento`
  MODIFY `id_agendamento` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=10;
--
-- AUTO_INCREMENT for table `avulsa`
--
ALTER TABLE `avulsa`
  MODIFY `id_avulsa` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=11;
--
-- AUTO_INCREMENT for table `cliente`
--
ALTER TABLE `cliente`
  MODIFY `id_cliente` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=30;
--
-- AUTO_INCREMENT for table `pdv`
--
ALTER TABLE `pdv`
  MODIFY `id_venda` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=15;
--
-- AUTO_INCREMENT for table `produto`
--
ALTER TABLE `produto`
  MODIFY `id_produto` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=7;
--
-- AUTO_INCREMENT for table `usuario`
--
ALTER TABLE `usuario`
  MODIFY `id_usuario` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=5;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
