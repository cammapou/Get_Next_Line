/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cammapou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 11:47:43 by cammapou          #+#    #+#             */
/*   Updated: 2018/01/09 17:39:23 by cammapou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
 **
 ** • Le premier paramètre est le file descriptor depuis lequel lire.
 **
 ** • Le second paramètre est l’adresse d’un pointeur sur caractère qui servira à stocker
 ** la ligne lue sur le file descriptor.
 ** 
 **	• La valeur de retour peut être 1, 0 ou -1 selon qu’une ligne a été lue, que la lecture est terminée ou bien qu’une erreur est survenue respectivement.
 **
 ** • Votre fonction get_next_line doit renvoyer son resultat sans le ’\n’.
 **
 ** • Un appel en boucle à votre fonction get_next_line permettra donc de lire le texte disponible sur un descripteur de fichier une ligne à la fois jusqu’à la 
 ** fin du texte, quelque soit la taille du texte en question ou d’une de ses lignes.
 **
 ** • Assurez-vous que votre fonction se comporte bien lorsqu’elle lit depuis un fichier, depuis l’entrée standard, depuis une redirection, etc.
 **
 ** • Votre fichier get_next_line.h doit au moins contenir le prototype de la fonction get_next_line et une macro permettant de choisir la taille du buffer de 
 ** lecture de read. Cette valeur sera modifiée en soutenance pour évaluer la robustesse de votre rendu. Cette macro devra impérativement s’appeler BUFF_SIZE.
 ** 
 ** • On considère que get_next_line a un comportement indeterminé si entre deux appels, un même descripteur de fichier désigne deux fichiers différents 
 ** alors que la lecture du premier fichier n’était pas terminée.
 **
 ** • On considère également qu’un appel à la fonction lseek(2) n’aura jamais lieu entre deux appels à get_next_line sur un même descripteur de fichier.
 **
 ** • On considère enfin que get_next_line a un comportement indeterminé́ en cas de lecture dans un fichier binaire. Cependant, si vous le souhaitez, 
 ** vous pouvez rendre ce comportement cohérent.
 **
 ** • Les variables globales sont interdites.
 **
 ** • Les variables statiques sont autorisées.
 **
 ** test des leaks faire une boucle infinie dans le main avant le return et executer le programe avec leaks a.out par exemple.
 ** 
 **	----------------------------------------------------------------------------------------------------------------------------------------
 **
 ** 													MON PROGRAMME GET NEXT LINE 
 **
 **	1. Controler si les variable sont bien initialiser, vérifier le fd, remplissage du buffer avec '\0'.
 ** 
 ** 2. Crée une allocation dynamique de mémoire pour le char **line pour permettre de copier buf dans line si l'alllocation 
 **	   echoue ma condition renvois 0.
 ** 
 ** 3. Je crée une boucle pour lire le fichier, j'ai déclaré une variable "ret" pour récupérer le nombre d'octet lus.
 ** 
 ** 4. Pendant la lecture j'utilise la fonction "ft_strjoin" pour permetre de copier correctement buf dans line 
 **    caractere par caractere (faire attention au fuites memoire par la suite retrouver la tête pour pouvoir la free).
 **	 
 **	5. Je crée une condition dans la boucle de lecture, j'utilise la fonction "ft_strchr" dans le buffer pour permettre 
 **	   a ma boucle de s'arreter a la rencontre d'un retour a la ligne je quitte avec "break" .
 **	
 **	6. Je dois récupérer le reste qui a été lus et enregistrer dans ligne et le placé dans une variable static de type char.  
 ** 
 ** 7 . 
 ** 
 **
 **
 */


int		get_next_line(const int fd, char **line)
{
	char			buf[BUF_SIZE + 1];
	static char		*rest;
	int ret;
	char i;
	int j;

	j = 0;
	i = 0;
	if (!line || fd < 0)
		return (-1);
	ft_bzero(buf, BUF_SIZE);
	if ((*line = (char *)malloc(sizeof(char) * 1)) == NULL)
		return (0);
	while ((ret = read(fd, buf, BUF_SIZE)))
	{
		*line = ft_strjoin(*line, buf);
		if (ft_strchr(buf, '\n'))	
			break;
	}
	//line[i][j] = '\0';
	while (line[i])
	{
		rest = ft_strchr(*line, '\n') + 1;
		i++;
	}
	printf("tmp = |%s|\n", rest);
	return (0);
}