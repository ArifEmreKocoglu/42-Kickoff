FROM debian:10
RUN apt-get update
RUN apt-get install mariadb-server -y
COPY ./conf/mariadb_server.cnf /etc/mysql/mariadb.conf.d/
COPY ./tools /var/www/
RUN service mysql start
RUN mysql < /var/www/set_data.sql
EXPOSE 3306
CMD ["mysqld"]