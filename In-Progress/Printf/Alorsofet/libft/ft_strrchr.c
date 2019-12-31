/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strrchr.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amonteli <amonteli@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/09 15:40:35 by amonteli     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/14 01:43:04 by amonteli    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	int		count;
	char	*found;

	count = -1;
	found = 0;
	while (s[++count])
		if (s[count] == c)
			found = (char *)s + count;
	if (s[count] == c)
		return (char *)(s + count);
	if (found != 0)
		return (found);
	return (0);
}
