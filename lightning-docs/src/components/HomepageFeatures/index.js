import clsx from 'clsx';
import Heading from '@theme/Heading';
import styles from './styles.module.css';

const FeatureList = [
  {
    title: 'Easy to use',
    Svg: require('@site/static/img/lightning_logo.svg').default,
    description: (
      <>
        With Lightning, users can easily program advanced autonomous routines using features like PID controllers, odometry, pure pursuit, and more.
      </>
    ),
  },
  {
    title: 'Inspired by VEX community',
    Svg: require('@site/static/img/vex_logo.svg').default,
    description: (
      <>
        This project could not exist without the support of the <code>VEX</code> community. I hope this library can help many programmers around! 😉
    
      </>
    ),
  },

  {
    title: 'Powered by PROS',
    Svg: require('@site/static/img/logo_completo_PROS.svg').default,
    description: (
      <>
        Program your robot with <code>PROS</code>. Lightning is built on <code>PROS</code> to enhance your programming experience 🚀.
    
      </>
    ),
  },

];

function Feature({Svg, title, description}) {
  return (
    <div className={clsx('col col--4')}>
      <div className="text--center">
        <Svg className={styles.featureSvg} role="img" />
      </div>
      <div className="text--center padding-horiz--md">
        <Heading as="h3">{title}</Heading>
        <p>{description}</p>
      </div>
    </div>
  );
}

export default function HomepageFeatures() {
  return (
    <section className={styles.features}>
      <div className="container">
        <div className="row">
          {FeatureList.map((props, idx) => (
            <Feature key={idx} {...props} />
          ))}
        </div>
      </div>
    </section>
  );
}
