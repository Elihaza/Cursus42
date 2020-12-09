<?php
/**
 * The base configuration for WordPress
 *
 * The wp-config.php creation script uses this file during the
 * installation. You don't have to use the web site, you can
 * copy this file to "wp-config.php" and fill in the values.
 *
 * This file contains the following configurations:
 *
 * * MySQL settings
 * * Secret keys
 * * Database table prefix
 * * ABSPATH
 *
 * @link https://wordpress.org/support/article/editing-wp-config-php/
 *
 * @package WordPress
 */

// ** MySQL settings - You can get this info from your web host ** //
/** The name of the database for WordPress */
define( 'DB_NAME', 'wordpress' );

/** MySQL database username */
define( 'DB_USER', 'username' );

/** MySQL database password */
define( 'DB_PASSWORD', 'password' );

/** MySQL hostname */
define( 'DB_HOST', 'mysql' );

/** Database Charset to use in creating database tables. */
define( 'DB_CHARSET', 'utf8mb4' );

/** The Database Collate type. Don't change this if in doubt. */
define( 'DB_COLLATE', '' );

/**#@+
 * Authentication Unique Keys and Salts.
 *
 * Change these to different unique phrases!
 * You can generate these using the {@link https://api.wordpress.org/secret-key/1.1/salt/ WordPress.org secret-key service}
 * You can change these at any point in time to invalidate all existing cookies. This will force all users to have to log in again.
 *
 * @since 2.6.0
 */
define( 'AUTH_KEY',         '.yhVpO%z`)Lk[yrP%dkQ?Hto&*MOW=Bke!RsfW]Lc?us=^J76ZhXw)~30.9q}50@' );
define( 'SECURE_AUTH_KEY',  ';&l@=V1+uE&)i5b<DgL$Ok#wP,*aASs?Gwoi*D45E.#F,hI3n&v]U.[+=u1c!+>t' );
define( 'LOGGED_IN_KEY',    '/=l>})9A=&]Pvn@3mE8)NeEi7Q]jmYYxD,ybn1a?:}*0T~x=;]4E>9R1{^Qx8**Y' );
define( 'NONCE_KEY',        'ZvggdW+Ibuhj|d|;>-})(ta[9!O!d>25y=neU_(PCUWV*x(T=~&kApl}-gIL65f(' );
define( 'AUTH_SALT',        'E>CTsPo{(6Un:lFQUDrUHE5y,gQx&EX<Un2&P_Y]88xAu7o0t*hRX;I)J1& .OXf' );
define( 'SECURE_AUTH_SALT', 'ChQC*LcmIcoH4QC[?EZtl|h~5&MC_sk>CN^[2WI=S=&Sd]bt@5t,`Eui73B7x0zV' );
define( 'LOGGED_IN_SALT',   'iY)5zqxoy_BsI3fPk2JAX,rTsa-$rff*G{DpQL$I))$&p +F&r>*O:.uvkJ}45OY' );
define( 'NONCE_SALT',       'k;&zqndnF-VMJwMTPzW0}(W=59VvW8(7tIzfi_3d:!7}A.>*feH;{&vo Rwa@e.q' );

/**#@-*/

/**
 * WordPress Database Table prefix.
 *
 * You can have multiple installations in one database if you give each
 * a unique prefix. Only numbers, letters, and underscores please!
 */
$table_prefix = 'wp_';

/**
 * For developers: WordPress debugging mode.
 *
 * Change this to true to enable the display of notices during development.
 * It is strongly recommended that plugin and theme developers use WP_DEBUG
 * in their development environments.
 *
 * For information on other constants that can be used for debugging,
 * visit the documentation.
 *
 * @link https://wordpress.org/support/article/debugging-in-wordpress/
 */
define( 'WP_DEBUG', true );

/* That's all, stop editing! Happy publishing. */

/** Absolute path to the WordPress directory. */
if ( ! defined( 'ABSPATH' ) ) {
	define( 'ABSPATH', __DIR__ . '/' );
}

/** Sets up WordPress vars and included files. */
require_once ABSPATH . 'wp-settings.php';
