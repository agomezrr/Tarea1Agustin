import os
import pandas as pd
import seaborn as sns
import matplotlib.pyplot as plt

def hacerGraficos():

    dir_csv = "../data/measurements/salida_sort.csv"
    dir_plot = "../data/plots/"

    os.makedirs(dir_plot, exist_ok=True)

    try:
        datos = pd.read_csv(dir_csv)
    except FileNotFoundError:
        print("No se encontro el archivo " + dir_csv)
        return
    
    # Promediar muestras
    promedio_datos = datos.groupby(['Algoritmo', 'N', 'Tipo', 'Dominio'])['Tiempo-ms'].mean().reset_index()

    tipos = promedio_datos['Tipo'].unique()
    dominios = promedio_datos['Dominio'].unique()

    print("Se estan generando los graficos")

    # Se crean graficos por cada tipo (ascedente, descendente, aleatorio)
    for tip in tipos:
        for dom in dominios:
            plt.figure(figsize=(12, 7))
            
            sub = promedio_datos[(promedio_datos['Tipo']== tip) & (promedio_datos['Dominio']== dom)]
            sns.lineplot(data=sub, x='N', y='Tiempo-ms', hue='Algoritmo', marker='o', linewidth=2)

            plt.title(f'Tiempos de Ejecucion por Arreglo {tip.capitalize()} (Dominio {dom})', fontsize=13)
            plt.xlabel('Tamaño del Arreglo N', fontsize=11)
            plt.ylabel('Tiempo promedio en us', fontsize=11)

            plt.xscale('log')
            plt.grid(True, which="both", ls="--", alpha=0.6)
            plt.legend(title='Algoritmo', bbox_to_anchor=(1.05, 1), loc='upper left')

            nombreArchivo = f"plot_{tip}_{dom}.png"
            direccionArchivo = os.path.join(dir_plot, nombreArchivo)
            plt.savefig(direccionArchivo, bbox_inches='tight', dpi=300)
            plt.close()
            print("Se ha creado ", nombreArchivo)
        
    print("\n Los graficos se guardaron en " + dir_plot)

if __name__ == "__main__":
    hacerGraficos()
