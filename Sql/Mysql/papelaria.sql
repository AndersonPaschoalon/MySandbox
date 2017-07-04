CREATE TABLE `Categorias` (
	`Id` INT NOT NULL AUTO_INCREMENT,
	`Nome` VARCHAR(255) NOT NULL UNIQUE,
	`Descricao` VARCHAR(255) UNIQUE,
	`subCategoria` VARCHAR(255),
	`ativo` BOOLEAN NOT NULL,
	PRIMARY KEY (`Id`)
);

CREATE TABLE `ProdutosCategorias` (
	`IdCategorias` INT NOT NULL,
	`IdProdutos` INT NOT NULL,
	PRIMARY KEY (`IdCategorias`,`IdProdutos`)
);

CREATE TABLE `Produtos` (
	`Id` INT NOT NULL AUTO_INCREMENT,
	`CodigoInterno` DECIMAL NOT NULL UNIQUE,
	`CodigoBarras` DECIMAL NOT NULL UNIQUE,
	`Nome` VARCHAR(255) NOT NULL UNIQUE,
	`PrecoCusto` DECIMAL,
	`PrecoVenda` DECIMAL NOT NULL,
	`EstoqueMinimo` DECIMAL NOT NULL,
	`EstoqueAtual` DECIMAL NOT NULL,
	`ativo` BOOLEAN NOT NULL,
	PRIMARY KEY (`Id`)
);

ALTER TABLE `ProdutosCategorias` ADD CONSTRAINT `ProdutosCategorias_fk0` FOREIGN KEY (`IdCategorias`) REFERENCES `Categorias`(`Id`);

ALTER TABLE `ProdutosCategorias` ADD CONSTRAINT `ProdutosCategorias_fk1` FOREIGN KEY (`IdProdutos`) REFERENCES `Produtos`(`Id`);

