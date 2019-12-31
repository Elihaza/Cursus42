/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strchr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amonteli <amonteli@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/08 19:41:47 by amonteli     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/14 01:40:17 by amonteli    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	int		count;

	count = -1;
	while (s[++count])
		if (s[count] == c)
			return (char *)(s + count);
	if (s[count] == c)
		return (char *)(s + count);
	return (0);
}
